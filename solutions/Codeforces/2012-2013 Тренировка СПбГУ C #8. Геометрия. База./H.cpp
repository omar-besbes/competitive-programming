#include <bits/stdc++.h>
using namespace std;
#define input "distance3.in"
#define output "distance3.out"

struct P {
   double x, y;
   void read() { cin >> x >> y; }
   P operator-(P p) const { return P{x - p.x, y - p.y}; }
   double dot(P p) const { return x * p.x + y * p.y; }
   double dist(P p) const {
      return sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y));
   }
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
   double ans;
   if ((v - u).dot(x - u) <= 0) {
      ans = u.dist(x);
   } else {
      auto [a, b, c] = getline(u, v);
      ans = abs(a * x.x + b * x.y + c) / sqrt(a * a + b * b);
   }
   cout << fixed << setprecision(10);
   cout << ans;
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