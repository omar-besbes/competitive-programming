#include <bits/stdc++.h>
using namespace std;
#define input "angle1.in"
#define output "angle1.out"
const double pi = acos(-1);

void solve() {
   int x, y;
   cin >> x >> y;
   auto angle = atan2(y, x);
   if (angle < 0) angle += 2 * pi;
   cout << fixed << setprecision(10) << angle;
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);
   if (fopen(input, "r")) {
      freopen(input, "r", stdin);
      freopen(output, "w+", stdout);
   }

   int t = 1;
   // cin >> t;
   while (t--) solve();
}