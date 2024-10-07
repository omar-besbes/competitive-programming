#include "bits/stdc++.h"

using namespace std;

int n, m;
vector<vector<pair<int, int>>> adj;
vector<int> dp;

int longest_path(int cu = n - 1) {
   if (dp[cu] == INT_MIN) {
      for (const auto &item : adj[cu]) {
         dp[cu] = max(dp[cu], longest_path(item.first) + item.second);
      }
   }
   return dp[cu];
}

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);

   cin >> n >> m;
   adj.assign(n, {});
   dp.assign(n, INT_MIN);
   for (int i = 0; i < m; ++i) {
      int x, y, d;
      cin >> x >> y >> d;
      adj[y - 1].emplace_back(x - 1, d);
   }

   dp[0] = 0;
   cout << longest_path() << "\n";
}