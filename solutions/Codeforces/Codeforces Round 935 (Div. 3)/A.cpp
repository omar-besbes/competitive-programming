#include "bits/stdc++.h"

using namespace std;

int main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);
   int t;
   cin >> t;
   while (t--) {
      int a, b, c;
      cin >> a >> b >> c;

      cout << (b % 3 == 0 || c + b % 3 > 2
                   ? a + ((c + b) / 3) + ((c + b) % 3 > 0 ? 1 : 0)
                   : -1)
           << "\n";
   }
}