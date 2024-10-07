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
      int l[3], sum = 0;
      bool test = true;
      for (auto &i : l) {
         cin >> i;
         sum += i;
      }

      for (int i = 0; i < 3; i++) {
         if (l[i] == sum - l[i]) {
            cout << "YES\n";
            test = false;
            break;
         } else if (l[i] > 1 && l[i] % 2 == 0) {
            int a[2], j = 0;
            for (int k = 0; k < 3; ++k) {
               if (k == i) continue;
               a[j++] = l[k];
            }
            if (a[0] == a[1]) {
               cout << "YES\n";
               test = false;
               break;
            }
         }
      }

      if (test) cout << "NO\n";
   }

   return 0;
}