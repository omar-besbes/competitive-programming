#include "bits/stdc++.h"
using namespace std;

int main() {
   int n;
   cin >> n;

   vector<int> fact;
   for (int i = 2; i * i <= n; i++)
      if (n % i == 0) {
         if (i != n / i) cout << i << "\n";
         fact.push_back(i);
      }

   if (fact.size())
      for (int i = fact.size() - 1; i >= 0; i--) {
         cout << n / fact[i] << "\n";
      }
   else
      cout << "0\n";
}