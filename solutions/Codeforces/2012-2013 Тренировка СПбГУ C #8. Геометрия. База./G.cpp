#include <bits/stdc++.h>
using namespace std;
#define input "distance2.in"
#define output "distance2.out"

struct P {
   double x, y;
   void read() { cin >> x >> y; }
};

tuple<double, double, double> getline(P u, P v) {
   double a = u.y - v.y;
   double b = v.x - u.x;
   double c = -a * u.x - b * u.y;
   return {a, b, c};
}

void solve() {
   P x, u, v;
   x.read(), u.read(), v.read();
   auto [a, b, c] = getline(u, v);
   cout << fixed << setprecision(10);
   cout << abs(a * x.x + b * x.y + c) / sqrt(a * a + b * b);
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