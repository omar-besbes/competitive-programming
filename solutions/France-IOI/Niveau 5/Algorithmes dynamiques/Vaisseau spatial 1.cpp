#include "bits/stdc++.h"
using namespace std;

#define N 2000 + 2
#define M 50

int n, m, p;
int a[N][M];

int getMax(int i, int j) {
   int res = a[i - 1][j];
   if (j > 0) res = max(res, a[i - 1][j - 1]);
   if (j < m - 1) res = max(res, a[i - 1][j + 1]);
   return res;
}

int main() {
   cin >> n >> m >> p;
   for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) cin >> a[i][j];

   for (int i = 1; i < n; i++)
      for (int j = 0; j < m; j++) a[i][j] += getMax(i, j);

   cout << a[n - 1][p] << "\n";

   return 0;
}