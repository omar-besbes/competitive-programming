#include <bits/stdc++.h>
using namespace std;

vector<set<int>> e;
vector<int> ans;

pair<int, int> dfs(int v, int p, int d = 0) {
   pair<int, int> maxD = {d, v};
   for (auto i : e[v])
      if (i != p) maxD = max(maxD, dfs(i, v, d + 1));
   ans[v] = max(ans[v], d);
   return maxD;
}

void solve() {
   int n;
   cin >> n;
   e.resize(n + 1);
   ans.resize(n + 1);
   vector<int> deg(n + 1);
   for (int i = 0; i < n - 1; i++) {
      int a, b;
      cin >> a >> b;
      deg[a]++, deg[b]++;
      e[a].insert(b);
      e[b].insert(a);
   }

   int leaf = 1;
   for (int i = 1; i <= n; i++)
      if (deg[i] == 1) {
         leaf = i;
         break;
      }

   auto [_, e1] = dfs(leaf, leaf);
   auto [d, e2] = dfs(e1, e1);
   dfs(e2, e2);

   for (int i = 0; i < n; i++) cout << ans[i + 1] << " ";
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);

   int t = 1;
   // cin >> t;
   while (t--) solve();
}