#include <bits/stdc++.h>

using namespace std;

int main() {
   //    ios::sync_with_stdio(false);
   //    cin.tie(nullptr);
   //    cout.tie(nullptr);
   //    freopen("name.in", "r", stdin);
   //    freopen("input.txt", "r", stdin);
   //    freopen("output.txt", "w+", stdout);

   int t;
   cin >> t;
   while (t--) {
      long long hc, dc, hm, dm;
      cin >> hc >> dc >> hm >> dm;
      long long k, w, a;
      cin >> k >> w >> a;

      long long x = 0;
      while (x <= k && ceil(((double)hc + x * a) / dm) <
                           ceil((double)hm / (dc + (k - x) * w))) {
         x++;
      }

      if (x > k || ceil(((double)hc + x * a) / dm) <
                       ceil((double)hm / (dc + (k - x) * w)))
         cout << "NO\n";
      else
         cout << "YES\n";
   }

   return 0;
}