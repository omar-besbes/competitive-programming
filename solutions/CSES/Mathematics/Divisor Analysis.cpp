#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>

const ll mod = 1e9 + 7;

ll binpow(ll a, ll b, ll mod = mod) {
   if (b == 0) return 1;
   auto tmp = binpow(a, b / 2, mod);
   if (b & 1)
      return (tmp * tmp % mod) * a % mod;
   else
      return tmp * tmp % mod;
}

ll inv(ll a) { return binpow(a, mod - 2, mod); }

void solve() {
   int n;
   cin >> n;
   vector<pll> a(n);
   for (auto &i : a) cin >> i.first >> i.second;

   // num  is the number of divisors mod 1e9+7
   ll num = 1, sum = 1, prod = 1;
   for (auto [p, k] : a) {
      num *= (k + 1) % mod, num %= mod;
      sum *= (binpow(p, k + 1) - 1) * inv(p - 1) % mod, sum %= mod;
   }

   ;
   vector<ll> precompute(n);
   for (ll i = 0, num2 = 1; i < n; i++) {
      auto [p, k] = *(a.begin() + i);
      precompute[i] =
          binpow(p, num2 * (k * (k + 1) / 2 % (mod - 1)) % (mod - 1));
      num2 *= (k + 1) % (mod - 1), num2 %= mod - 1;
   }

   for (ll i = n - 1, num2 = 1; i >= 0; i--) {
      auto [p, k] = *(a.begin() + i);
      prod *= binpow(precompute[i], num2), prod %= mod;
      num2 *= (k + 1) % (mod - 1), num2 %= mod - 1;
   }

   cout << num << " " << sum << " " << prod << "\n";
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);

   int t = 1;
   // cin >> t;
   while (t--) solve();
}