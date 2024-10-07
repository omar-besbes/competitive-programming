#include <bits/stdc++.h>

using namespace std;

int main() {
   //    ios::sync_with_stdio(false);
   //    cin.tie(nullptr);
   //    cout.tie(nullptr);
   //    freopen("name.in", "r", stdin);
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w+", stdout);

   int t;
   cin >> t;
   while (t--) {
      int n;
      cin >> n;
      int a[n], maxi = 0, sum = 0, ans;
      for (int i = 0; i < n; i++) {
         cin >> a[i];
         maxi = max(maxi, a[i]);
      }
      for (int i = 0; i < n; ++i) {
         sum += maxi - a[i];
      }
      if (sum % 3 == 0)
         ans = sum / 3 * 2;
      else if (sum % 3 == 1)
         ans = sum / 3 * 2 + 1;
      else
         ans = sum / 3 * 2 + 2;
      cout << ans << '\n';
   }

   return 0;
}