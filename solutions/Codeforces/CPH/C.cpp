#include <bits/stdc++.h>

using namespace std;

int main() {
   //    ios::sync_with_stdio(false);
   //    cin.tie(nullptr);
   //    cout.tie(nullptr);
   //    freopen("name.in", "r", stdin);
   //    freopen("input.txt", "r", stdin);
   //    freopen("output.txt", "w+", stdout);

   int m, x[5] = {0, 0, 0, 0, 0};
   cin >> m;
   for (int i = 0; i < m; ++i) {
      int a, b;
      cin >> a >> b;
      x[a - 1]++;
      x[b - 1]++;
   }

   for (int i = 0; i < 5; ++i) {
      if (x[i] >= 3 || x[i] <= 1) {
         cout << "WIN";
         return 0;
      }
   }
   cout << "FAIL";

   return 0;
}