#include "bits/stdc++.h"
using namespace std;
typedef long double ld;

int main() {
   ld n, k, l;
   cin >> n >> k >> l;
   cout << fixed << setprecision(0);
   if (l > k - l) {
      ld bigside = ((n - 1) * k + 2 * l);
      ld smallside = ((n - 1) * k);
      ld ans =
          (bigside * bigside) - (smallside * smallside) - (n - 1) * (k * k);
      cout << ans << "\n";
   } else {
      cout << n * (2 * l) * (2 * l) << "\n";
   }
}