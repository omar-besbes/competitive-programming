#include <bits/stdc++.h>
#define NB_GROUPES_MAX 100000
using namespace std;

deque<int> sequence;
vector<int> Groupes;
int nbJ, nbG;

bool isNotNull(int a) { return a != 0; }

int getFirstSequence() {
   int x, i = 0;
   while (!all_of(Groupes.begin(), Groupes.end(), isNotNull)) {
      cin >> x;
      Groupes[x - 1]++;
      sequence.push_back(x);
      i++;
   }

   return i;
}

void simplify() {
   if (Groupes.empty()) return;
   while (Groupes[sequence.front() - 1] > 1) {
      Groupes[sequence.front() - 1]--;
      sequence.pop_front();
   }
}

void advance() {
   int x;
   cin >> x;
   Groupes[x - 1]++;
   Groupes[sequence.front() - 1]--;
   sequence.pop_front();
   sequence.push_back(x);
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);

   cin >> nbJ >> nbG;
   Groupes.assign(nbG, 0);

   int currIndex = getFirstSequence();
   simplify();
   int mini = min(nbJ, (int)sequence.size());

   while (currIndex < nbJ) {
      advance();

      if (all_of(Groupes.begin(), Groupes.end(), isNotNull)) {
         simplify();
         mini = min(mini, (int)sequence.size());
      }

      currIndex++;
   }
   cout << mini;

   return 0;
}