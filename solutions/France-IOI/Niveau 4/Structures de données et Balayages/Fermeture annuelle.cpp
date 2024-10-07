#include "bits/stdc++.h"

using namespace std;

bool compare(pair<int, int> &a, pair<int, int> &b) {
   if (a.first == b.first) return a.second < b.second;
   return a.first < b.first;
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);

   int maxA, nbF, maxInactif;
   cin >> maxA >> nbF;
   vector<pair<int, int>> I, newI;
   for (int i = 0; i < nbF; ++i) {
      int D, F;
      cin >> D >> F;
      if (D > F) {
         I.emplace_back(0, F);
         I.emplace_back(D, maxA);
      } else
         I.emplace_back(D, F);
   }
   sort(I.begin(), I.end(), compare);

   auto index = I.begin() + 1;
   newI.push_back(I.front());
   while (index != I.end()) {
      if (index->first <= newI.back().second)
         newI.back().second = max(index->second, newI.back().second);
      else
         newI.push_back(*index);
      index++;
   }

   index = newI.begin() + 1;
   maxInactif = maxA - newI.back().second + newI.front().first;
   while (index != newI.end()) {
      maxInactif = max(maxInactif, index->first - (index - 1)->second);
      index++;
   }
   cout << maxInactif;

   return 0;
}