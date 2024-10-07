#include <bits/stdc++.h>
using namespace std;

const int maxK = 30;

void solve() {
   int n, k;
   cin >> n >> k;
   vector<bitset<maxK>> a(n);
   for (auto &i : a) cin >> i;

   auto ans = k;
   for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
         ans = min(ans, (int)(a[i] ^ a[j]).count());
      }
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