#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
   int n, m;
   cin >> n >> m;
   set<pair<int, int>> s;
   for (int i = 0; i < m; i++) {
      int x, y;
      cin >> x >> y;
      s.insert({x, y});
   }
   for (int i = 0; i < n - 1; i++) {
      if (s.count({i + 1, i + 2})) {
         cout << 0 << " ";
      } else {
         cout << 1 << " ";
      }
   }
   cout << 0;
   cout << endl;
}

signed main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   int tt = 1;
   // cin >> tt;
   while (tt--) {
      solve();
   }
}