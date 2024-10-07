#include <bits/stdc++.h>

using namespace std;

int main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);
   //    freopen("name.in", "r", stdin);
   //   freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w+", stdout);
   int n, m;
   cin >> n >> m;
   char c, a[n][m];
   cin >> c;
   for (int i = 0; i < n; i++)
      for (int j = 0; j < m; ++j) cin >> a[i][j];
   if (m == 1) {
      for (int i = 0; i < n; ++i) {
         if (a[i][0] != c) {
            cout << "NO\n";
            return 0;
         }
      }
      cout << "YES\n";
      return 0;
   }
   for (int i = 0; i < m; ++i) {
      if (a[n - 1][i] != c) {
         cout << "NO\n";
         return 0;
      }
   }
   cout << "YES\n";
   return 0;
}