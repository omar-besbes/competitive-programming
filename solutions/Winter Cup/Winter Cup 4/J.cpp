#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> v[200005], cu[200005];
int a[200005], is_sp[200005];
long long ans;

int dfs(int idx, int anc) {
   for (int i = 0; i < v[idx].size(); ++i) {
      if (v[idx][i] != anc) {
         int x = dfs(v[idx][i], idx);
         if (x != -1) cu[idx].push_back(x);
      }
   }
   sort(cu[idx].begin(), cu[idx].end());
   reverse(cu[idx].begin(), cu[idx].end());
   // cout << idx << ' ';
   if (cu[idx].empty()) {
      if (is_sp[idx]) {
         // cout << a[idx] << '\n';
         return a[idx];
      }
      // cout << "0\n";
      return -1;
   }
   while (cu[idx].size() > 1) {
      ans += cu[idx].back();
      cu[idx].pop_back();
   }
   // cout << max(a[idx], cu[idx]][0]) << '\n';
   int ma = max(a[idx], cu[idx][0]);
   return ma;
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);
   //    freopen("name.in", "r", stdin);
   //   freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w+", stdout);
   cin >> n >> m;
   ans = 0;
   for (int i = 0; i < m; ++i) {
      int x;
      cin >> x;
      is_sp[x] = 1;
   }
   for (int i = 1; i <= n; ++i) {
      cin >> a[i];
   }
   for (int i = 0; i < n - 1; ++i) {
      int x, y;
      cin >> x >> y;
      v[x].push_back(y);
      v[y].push_back(x);
   }
   ans += dfs(1, 1);
   cout << ans << '\n';
   return 0;
}