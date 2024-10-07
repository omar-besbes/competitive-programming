#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod = 1e9 + 7;

void solve() {
   ll n;
   cin >> n;

   ll ans = 0;
   for (ll i = 1; i * i <= n; i++) ans = (ans + n / i * i) % mod;

   for (ll i = 1; i <= n / (floor(sqrt(n)) + 1); i++) {
      ll l = (n / (i + 1) + 1) % mod, r = (n / i) % mod;
      // supposedly, sum = (r - l + 1) * (r + l) / 2
      // but due to modulus, (r - l + 1) * (r + l) isn't always pair
      // so, to avoid calculating the inverse modulo of 2,
      // sum = r*(r+1)/2 - l*(l-1)/2
      ll sum = (r * (r + 1) / 2 % mod) - (l * (l - 1) / 2 % mod);
      ans = (ans + (i * sum % mod)) % mod;
   }

   cout << ans << "\n";
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);

   int t = 1;
   // cin >> t;
   while (t--) solve();
}