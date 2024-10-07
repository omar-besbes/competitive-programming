#include "bits/stdc++.h"
using namespace std;

#define N 100 + 1

int n;
vector<long long> a[N];

int main() {
   cin >> n;
   for (int i = 0; i < n; i++) {
      a[i].assign(i + 1, 0);
      for (int j = 0; j < i + 1; j++) cin >> a[i][j];
   }

   for (int i = n - 2; i >= 0; i--)
      for (int j = 0; j < i + 1; j++)
         a[i][j] += max(a[i + 1][j], a[i + 1][j + 1]);

   cout << a[0][0] << "\n";

   return 0;
}