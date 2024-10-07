#include "bits/stdc++.h"

using namespace std;

int main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);

   int t;
   cin >> t;
   while (t--) {
      long long a, b, c, res = 0;
      cin >> a >> b >> c;
      if (min(a, b) > c + 1) {
         cout << "2\n";
      } else {
         cout << c / a + c / b + 2 << "\n";
      }
   }
}