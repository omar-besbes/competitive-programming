#include <bits/stdc++.h>
using namespace std;
#define input "distance5.in"
#define output "distance5.out"

struct P {
   double x, y;
   void read() { cin >> x >> y; }
   P operator-(P p) const { return P{x - p.x, y - p.y}; }
   double dot(P p) const { return x * p.x + y * p.y; }
   double cross(P p) const { return x * p.y - y * p.x; }
   double cross(P a, P b) const { return (a - *this).cross(b - *this); }
   double dist(P p) const {
      return sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y));
   }
   bool between(P a, P b) {
      return (x >= min(a.x, b.x) && x <= max(a.x, b.x)) &&
             (y >= min(a.y, b.y) && y <= max(a.y, b.y));
   }
};

tuple<double, double, double> getline(P u, P v) {
   double a = u.y - v.y;
   double b = v.x - u.x;
   double c = -a * u.x - b * u.y;
   return {a, b, c};
}

double pointRayDist(P x, P u, P v) {
   double ans;
   if ((v - u).dot(x - u) <= 0) {
      ans = u.dist(x);
   } else if ((u - v).dot(x - v) <= 0) {
      ans = v.dist(x);
   } else {
      auto [a, b, c] = getline(u, v);
      ans = abs(a * x.x + b * x.y + c) / sqrt(a * a + b * b);
   }
   return ans;
}

bool intersect(P a, P b, P u, P v) {
   auto sgn = [](double x) { return x >= 0 ? x ? 1 : 0 : -1; };
   if (a.cross(b, u) == 0 && a.cross(b, v) == 0) {
      return a.between(u, v) || b.between(u, v) || u.between(a, b) ||
             v.between(a, b);
   } else {
      return sgn(a.cross(b, u)) != sgn(a.cross(b, v)) &&
             sgn(u.cross(v, a)) != sgn(u.cross(v, b));
   }
}

void solve() {
   P a, b, u, v;
   a.read(), b.read(), u.read(), v.read();
   double ans;
   if (intersect(a, b, u, v))
      ans = 0;
   else
      ans = min({pointRayDist(a, u, v), pointRayDist(b, u, v),
                 pointRayDist(u, a, b), pointRayDist(v, a, b)});
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