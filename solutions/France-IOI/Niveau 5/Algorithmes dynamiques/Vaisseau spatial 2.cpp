#include "bits/stdc++.h"
using namespace std;

#define N 2000 + 1
#define M 50

int n, m, p;
int a[N][M];

pair<int, int> getMax(int i, int j) {
   pair<int, int> res = make_pair(a[i - 1][j], 0);
   // between "stay" and "left", choose "stay"
   if (j > 0 && a[i - 1][j - 1] > res.first)
      res = make_pair(a[i - 1][j - 1], -1);
   // between "left" and "right", choose "left"
   // between "stay" and "right", choose "stay"
   if (j < m - 1 && a[i - 1][j + 1] > res.first)
      res = make_pair(a[i - 1][j + 1], 1);
   return res;
}

void print() {
   for (int i = 0; i < n + 1; i++) {
      for (int j = 0; j < m; j++) cout << setw(2) << a[i][j];
      cout << "\n";
   }
   cout << "\n";
}

int main() {
   cin >> n >> m >> p;
   for (int i = 0; i < n + 1; i++)
      for (int j = 0; j < m; j++) cin >> a[i][j];

   for (int i = 1; i < n + 1; i++)
      for (int j = 0; j < m; j++) a[i][j] += getMax(i, j).first;

   for (int i = n - 1; i > 0; i--) {
      auto next = getMax(i, p);
      p += next.second;
      cout << next.second << " ";
   }

   return 0;
}