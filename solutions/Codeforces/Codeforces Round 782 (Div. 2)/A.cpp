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
      int n, r, b;
      cin >> n >> r >> b;
      int coeff = 1;
      while (r > coeff * (b + 1)) coeff++;
      int leftover = r - (coeff - 1) * (b + 1);
      for (int i = 0; i < b; ++i) {
         for (int j = 0; j < coeff - 1; ++j) cout << "R";
         if (leftover) {
            cout << "R";
            leftover--;
         }
         cout << "B";
      }
      for (int j = 0; j < coeff - 1; ++j) cout << "R";
      if (leftover) {
         cout << "R";
      }
      cout << "\n";
   }

   return 0;
}