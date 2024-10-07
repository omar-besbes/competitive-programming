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
      int n, k;
      cin >> n >> k;
      if (k == 1) {
         cout << "YES\n";
         for (int i = 0; i < n; ++i) {
            cout << i + 1 << '\n';
         }
      } else {
         if (n % 2 == 0) {
            cout << "YES\n";
            for (int i = 0; i < n; i++) {
               int start = (i % 2 == 0) ? i * k + 1 : (i - 1) * k + 2;
               for (int j = start; j < 2 * k + start; j += 2) {
                  cout << j << ' ';
               }
               cout << '\n';
            }
         } else
            cout << "NO\n";
      }
   }

   return 0;
}