#include <bits/stdc++.h>
using namespace std;

int n, q;
vector<set<int>> e;
vector<vector<int>> up;

void buildAncestors(int v, int p, int d = 0) {
   up[v].push_back(p);
   for (int i = 1; (1 << i) <= d; i++) up[v].push_back(up[up[v][i - 1]][i - 1]);

   for (int u : e[v])
      if (u != p) buildAncestors(u, v, d + 1);
}

int msb(int n) { return 31 - __builtin_clz(n); }

int query(int x, int k) {
   if (k == 0) return x;
   if (x == 1) return -1;

   int _msb = msb(k), l = up[x].size();
   if (_msb < l)
      return query(up[x][_msb], k - (1 << _msb));
   else
      return -1;
}

void solve() {
   cin >> n >> q;
   up.resize(n + 1);
   e.resize(n + 1);
   for (int i = 2; i <= n; i++) {
      int p;
      cin >> p;
      e[p].insert(i);
   }

   buildAncestors(1, 1);

   for (int i = 0; i < q; i++) {
      int x, k;
      cin >> x >> k;

      cout << query(x, k) << "\n";
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