#include <bits/stdc++.h>
using namespace std;

void solve() {
   int n;
   cin >> n;
   vector<int> a(2 * n);
   long long ans = 0;
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
         int x;
         cin >> x;
         a[n + i - j] = max(a[n + i - j], -x);
      }
   }
   for (int i = 0; i < 2 * n; i++) {
      // cout << a[i] << " ";
      ans += a[i];
   }
   cout << ans << "\n";
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);

   int t = 1;
   cin >> t;
   while (t--) solve();
}