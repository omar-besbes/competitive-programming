#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
   ll n, k;
   cin >> n >> k;
   vector<ll> a(k);
   for (auto &i : a) cin >> i;

   ll ans = 0;
   double max_log_value = log(n);
   for (ll i = 1; i < (1 << k); i++) {
      auto bitmask = bitset<20>(i);
      auto sign = bitmask.count() & 1 ? 1 : -1;

      ll combination = 1;
      double log_value = 0;
      for (int j = 0; j < k; j++)
         if (bitmask.test(j)) {
            combination *= a[j];
            log_value += log(a[j]);
         }

      if (log_value <= max_log_value) ans += sign * n / combination;
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