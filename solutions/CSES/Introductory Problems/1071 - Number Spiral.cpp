#include <bits/stdc++.h>
using namespace std;
#define input "input.in"
#define output "output.out"
#define ll long long
#define int ll

void solve() {
   int x, y, ans;
   cin >> x >> y;

   if (x > y) {
      int v = (x & 1 ? (x - 1) * (x - 1) + 1 : x * x);
      ans = v + (y - 1) * (x & 1 ? 1 : -1);
   } else {
      int v = (y & 1 ? y * y : (y - 1) * (y - 1) + 1);
      ans = v + (x - 1) * (y & 1 ? -1 : 1);
   }

   cout << ans << "\n";
}

int32_t main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);

   if (fopen(input, "r")) freopen(input, "r", stdin);
   if (fopen(output, "r")) freopen(output, "w+", stdout);

   int t = 1;
   cin >> t;
   while (t--) solve();
}
