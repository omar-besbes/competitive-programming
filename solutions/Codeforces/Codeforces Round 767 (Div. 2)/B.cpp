#include <bits/stdc++.h>

using namespace std;

int nbImpair(int l, int r) {
   int n = r - l + 1;
   if (l == r) {
      if (l == 1)
         return 1;
      else
         return 0;
   }
   if (n % 2 == 0) {
      return n / 2;
   } else {
      if (l % 2 == 0) {
         return (n - 1) / 2;
      } else
         return (n - 1) / 2 + 1;
   }
}

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
      int l, r, k;
      cin >> l >> r >> k;
      if (nbImpair(l, r) > k) {
         cout << "NO" << '\n';
      } else
         cout << "YES" << '\n';
   }

   return 0;
}