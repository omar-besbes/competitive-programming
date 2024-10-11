#include <bits/stdc++.h>
using namespace std;

bool compare(const pair<int, int> &a, const pair<int, int> &b) {
   if (a.first == b.first) return a.second < b.second;
   return a.first < b.first;
}

bool guideEstOccupe(vector<pair<int, int>> &G, pair<int, int> &I) {
   if (G.empty()) {
      G.push_back(I);
      return false;
   } else if (I.first >= G.back().second) {
      G.push_back(I);
      return false;
   }
   return true;
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);

   int nbGuides, nbGroupes;
   cin >> nbGuides >> nbGroupes;
   vector<pair<int, int>> emploi[nbGuides], intervalles;
   for (int i = 0; i < nbGroupes; ++i) {
      pair<int, int> temp;
      cin >> temp.first >> temp.second;
      intervalles.push_back(temp);
   }
   sort(intervalles.begin(), intervalles.end(), compare);
   for (int i = 0; i < nbGroupes; ++i) {
      int g = 0;
      while (g < nbGuides && guideEstOccupe(emploi[g], intervalles[i])) g++;
      if (g == nbGuides) {
         cout << 0;
         return 0;
      }
   }
   cout << 1;
   return 0;
}