#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
   int n, m, q;
   cin >> n >> m >> q;
   vector<vector<ll>> d(n, vector<ll>(n, LONG_LONG_MAX));
   for (int i = 0; i < m; i++) {
      int u, v;
      ll w;
      cin >> u >> v >> w;
      d[u - 1][v - 1] = min(w, d[u - 1][v - 1]);
      d[v - 1][u - 1] = min(w, d[v - 1][u - 1]);
   }

   for (int i = 0; i < n; i++) d[i][i] = 0;

   for (int k = 0; k < n; k++)
      for (int j = 0; j < n; j++)
         for (int i = 0; i < n; i++)
            if (d[i][k] < LONG_LONG_MAX && d[k][j] < LONG_LONG_MAX) {
               d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
               d[j][i] = min(d[j][i], d[j][k] + d[k][i]);
            }

   for (int i = 0; i < q; i++) {
      int u, v;
      cin >> u >> v;
      cout << (d[u - 1][v - 1] == LONG_LONG_MAX ? -1 : d[u - 1][v - 1]) << "\n";
   }
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);

   int t = 1;
   // cin >> t;
   while (t--) solve();
}