#include <bits/stdc++.h>
using namespace std;
#define input "angle2.in"
#define output "angle2.out"
const double pi = acos(-1);

void solve() {
   pair<double, double> a, b;
   cin >> a.first >> a.second >> b.first >> b.second;
   auto va = sqrt(a.first * a.first + a.second * a.second);
   auto vb = sqrt(b.first * b.first + b.second * b.second);
   auto ab = a.first * b.first + a.second * b.second;
   cout << fixed << setprecision(10) << acos(ab / (va * vb));
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