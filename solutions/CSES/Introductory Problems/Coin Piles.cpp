#include "bits/stdc++.h"
using namespace std;

void solve() {
   int a, b;
   cin >> a >> b;

   // auto op1 = ((a + b) / 3 + (a - b)) / 2;
   // auto op2 = ((a + b) / 3 - (a - b)) / 2;

   if ((a + b) % 3 == 0 && a <= 2 * b && b <= 2 * a)
      cout << "YES\n";
   else
      cout << "NO\n";
}

int main() {
   int t;
   cin >> t;
   while (t--) solve();
}