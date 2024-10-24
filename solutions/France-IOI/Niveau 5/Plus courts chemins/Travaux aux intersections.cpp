#include <bits/stdc++.h>
using namespace std;

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);

   int n, a;
   cin >> n >> a;

   vector<vector<int>> d(n, vector<int>(n, INT_MAX));
   for (int i = 0; i < a; i++) {
      int a, b, w;
      cin >> a >> b >> w;
      d[a - 1][b - 1] = w;
   }
   for (int i = 0; i < n; i++) d[i][i] = 0;

   for (int day = 1; day <= n; day++) {
      int k = day - 1;
      for (int i = 0; i < n; i++) {
         for (int j = 0; j < n; j++) {
            if (d[j][k] < INT_MAX && d[k][i] < INT_MAX)
               d[j][i] = min(d[j][i], d[j][k] + d[k][i]);
            if (d[i][k] < INT_MAX && d[k][j] < INT_MAX)
               d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
         }
      }

      for (int i = 0; i < n; i++) {
         for (int j = 0; j < n; j++)
            if (d[i][j] == INT_MAX)
               cout << '.' << " ";
            else
               cout << d[i][j] << " ";
         cout << "\n";
      }
      cout << "\n";
   }
}