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
      d[b - 1][a - 1] = w;
   }
   for (int i = 0; i < n; i++) d[i][i] = 0;

   for (int k = 0; k < n; k++) {
      for (int i = 0; i < n; i++) {
         for (int j = 0; j < n; j++) {
            if (d[i][k] < INT_MAX && d[k][j] < INT_MAX)
               d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
         }
      }
   }

   for (int i = 0; i < n; i++) {
      d[i][i] = 0;
      for (int j = 0; j < n; j++) cout << d[i][j] << " ";
      cout << "\n";
   }
}