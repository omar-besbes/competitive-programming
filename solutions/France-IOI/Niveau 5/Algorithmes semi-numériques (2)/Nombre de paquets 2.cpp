#include "bits/stdc++.h"

using namespace std;

vector<vector<unsigned long long>> c;

unsigned long long comb(int n, int p) {
   if (c[n][p] != -1) return c[n][p];
   if (p > n / 2) return comb(n, n - p);
   return c[n][p] = comb(n - 1, p) + comb(n - 1, p - 1);
}

int main() {
   int n, p;
   cin >> n >> p;

   c.assign(n + 1, vector<unsigned long long>(p + 1, -1));
   for (int i = 0; i < c.size(); ++i) {
      c[i][1] = i;
      c[i][0] = 1;
   }

   cout << comb(n, p) << "\n";
}