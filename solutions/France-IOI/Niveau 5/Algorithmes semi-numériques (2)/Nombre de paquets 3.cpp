#include "bits/stdc++.h"
using namespace std;

int main() {
   int n, p;
   cin >> n >> p;

   if (p == 1)
      cout << n << "\n";
   else {
      vector<int> suff(n + 1, 1);
      suff[n] = 0;
      while (p--) {
         for (int i = n - 1; i >= 0; i--) suff[i] += suff[i + 1];
      }

      cout << suff[0] << "\n";
   }
}