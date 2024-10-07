#include <bits/stdc++.h>
using namespace std;

int main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);

   int n, x;
   cin >> n >> x;
   vector<int> a(n);
   for (int i = 0; i < n; ++i) {
      cin >> a[i];
   }
   sort(a.begin(), a.end());
   int ans = 0;
   for (int i = 0, j = n - 1; j >= 0 && i <= j && i < n;) {
      if (i == j) {
         ans++;
         break;
      } else if (a[i] + a[j] <= x) {
         ans++;
         i++;
         j--;
      } else {
         ans++;
         j--;
      }
   }

   cout << ans << "\n";

   return 0;
}
