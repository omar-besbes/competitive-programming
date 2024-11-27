#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) x.begin(), x.end()
#define int ll

const int N = 1e6 + 1;

pair<int, int> good(int x) {
   int l = 0;
   int r = 1e6 + 100;
   int ans = 0;
   while (l <= r) {
      int m = (l + r) / 2;
      int sum = (m * (m + 1)) / 2;
      if (sum >= x) {
         r = m - 1;
         ans = m;
      } else {
         l = m + 1;
      }
   }
   return {(x - (ans * (ans - 1)) / 2), ans};
}

void solve() {
   int n, k;
   cin >> n >> k;
   auto [nb, m] = good(k);
   vector<int> ans(n);
   for (int i = 0; i < n - m; i++) ans[i] = i + 1;
   for (int i = n - m, j = n; i < n; i++, j--) ans[i] = j;

   // for (auto i : ans) cout << i << " ";
   // cout << endl;
   // cout << n - m - 1 << " " << k << endl  ;

   // if (n - m - 1 == -1) {
   //   for (auto i : ans) cout << i << " ";
   //   cout << endl;
   //   return;
   // }

   int idx = n - 1;
   while (idx >= 0 && nb--) {
      swap(ans[n - m - 1], ans[idx]);
      idx--;
   }

   // // cout << idx << " " << k << endl;
   for (auto i : ans) cout << i << " ";
   cout << endl;
}

signed main() {
   // freopen("a.txt", "w", stdout);
   ios::sync_with_stdio(false);
   cin.tie(0);

   int tt = 1;
   cin >> tt;
   while (tt--) {
      solve();
   }
}