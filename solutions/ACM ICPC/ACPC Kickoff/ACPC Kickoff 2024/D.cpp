#include "bits/stdc++.h"
using namespace std;

const long long mod = 998244353;

void solve() {
   long long n;
   cin >> n;
   long long ans = 0;
   long long curr = 1;
   for (long long l = 0; l < n; l++) {
      curr = curr * (n - l) % mod;
      ans = (ans + curr) % mod;
   }

   cout << ans << "\n";
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);

   int t;
   cin >> t;
   while (t--) solve();
}
