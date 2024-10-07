#include <bits/stdc++.h>
using namespace std;

int n, q, l, timer = 0;
vector<int> val, tin, tout;
vector<pair<long long, int>> ans;
vector<set<int>> e;
vector<vector<int>> up;

void dfs(int v = 1, int p = 1, int d = 0) {
   up[v][0] = p;
   tin[v] = ++timer;
   for (int i = 1; (1 << i) <= d; i++) up[v][i] = up[up[v][i - 1]][i - 1];

   for (auto c : e[v])
      if (c != p) dfs(c, v, d + 1);

   tout[v] = ++timer;
}

bool a_is_ancestor_of_b(int a, int b) {
   return tin[a] <= tin[b] && tout[a] >= tout[b];
}

int lca(int a, int b) {
   if (a_is_ancestor_of_b(a, b)) return a;
   if (a_is_ancestor_of_b(b, a)) return b;

   for (int i = l; i >= 0; i--)
      if (up[a][i] != -1 && !a_is_ancestor_of_b(up[a][i], b)) a = up[a][i];

   return up[a][0];
}

void merge(int v = 1, int p = 1) {
   ans[v] = make_pair(val[v], -1);
   for (auto c : e[v])
      if (c != p)
         merge(c, v), ans[v] = make_pair(ans[c].first + ans[v].first, -1);
}

void solve() {
   cin >> n >> q;
   l = ceil(log2(n));
   val.resize(n + 1);
   ans.resize(n + 1);
   e.resize(n + 1);
   up.resize(n + 1, vector<int>(l + 1, -1));
   tin.resize(n + 1), tout.resize(n + 1);
   for (int i = 0; i < n; i++) cin >> val[i + 1];

   for (int i = 0; i < n - 1; i++) {
      int a, b;
      cin >> a >> b;
      e[a].insert(b);
      e[b].insert(a);
   }

   dfs();

   for (int i = 0; i < q; i++) {
      int type;
      cin >> type;
      if (type == 1) {
         int s, x;
         cin >> s >> x;
         val[s] = x;
         ans[s].second = 1;
      } else {
         int s;
         cin >> s;
         if (a_is_ancestor_of_b(changed, s) || a_is_ancestor_of_b(s, changed))
            merge(s);
         cout << ans[s] << "\n";
      }
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