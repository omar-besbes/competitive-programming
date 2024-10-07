#include <bits/stdc++.h>
using namespace std;

bool zone(vector<pair<int, bool>> *N, vector<bool> &visited, int pos) {
   if (visited[pos]) return true;
   visited[pos] = true;
   int n = N[pos].size();
   for (int i = 0; i < n; i++) {
      if (N[pos][i].second) continue;
      if (zone(N, visited, N[pos][i].first)) return true;
      N[pos][i].second = true;
   }
   visited[pos] = false;
   return false;
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);

   int nbN, nbS;
   cin >> nbN >> nbS;
   vector<pair<int, bool>> N[nbN];
   for (int i = 0; i < nbS; ++i) {
      int n1, n2;
      cin >> n1 >> n2;
      N[n1 - 1].emplace_back(n2 - 1, false);
   }

   for (int i = 0; i < nbN; ++i) {
      vector<bool> V(nbN);
      if (zone(N, V, i)) {
         cout << "OUI";
         return 0;
      }
   }

   cout << "NON";

   return 0;
}