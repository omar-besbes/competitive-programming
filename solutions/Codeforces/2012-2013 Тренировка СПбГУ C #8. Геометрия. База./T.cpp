#include <bits/stdc++.h>
using namespace std;
#define input "raydist.in"
#define output "raydist.out"

struct P {
   double x, y;
   void read() { cin >> x >> y; }
   bool operator==(P p) const {
      return abs(x - p.x) <= 1e-6 && abs(y - p.y) <= 1e-6;
   }
   P operator-(P p) const { return P{x - p.x, y - p.y}; }
   P operator/(double d) const { return P{x / d, y / d}; }
   double dot(P p) const { return x * p.x + y * p.y; }
   double cross(P p) const { return x * p.y - y * p.x; }
   double cross(P a, P b) const { return (a - *this).cross(b - *this); }
   double dist(P p) const {
      return sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y));
   }
   P unit() { return *this / dist(P{0, 0}); }
};

struct L {
   double a, b, c;
   L(P u, P v) {
      a = u.y - v.y;
      b = v.x - u.x;
      c = -a * u.x - b * u.y;
   }
   P intersection(L l) {
      auto v1 = P{a, l.a};
      auto v2 = P{b, l.b};
      auto v3 = P{c, l.c};
      P p = {-v3.cross(v2) / v1.cross(v2), -v1.cross(v3) / v1.cross(v2)};
      return p;
   }
};

double pointRayDist(P x, P u, P v) {
   double ans;
   if ((v - u).dot(x - u) <= 0) {
      ans = u.dist(x);
   } else {
      auto [a, b, c] = L(u, v);
      ans = abs(a * x.x + b * x.y + c) / sqrt(a * a + b * b);
   }
   return ans;
}

bool intersect(P a, P b, P u, P v) {
   auto unita = (b - a).unit();
   auto unitv = (v - u).unit();
   if (unita == unitv) {
      return a.cross(b, u) == 0 &&
             ((b - a).dot(u - a) >= 0 || (v - u).dot(a - u) >= 0);
   } else {
      auto i = L(a, b).intersection(L(u, v));
      return (i - a).dot(b - a) >= 0 && (i - u).dot(v - u) >= 0;
   }
}

void solve() {
   P a, b, u, v;
   a.read(), b.read(), u.read(), v.read();
   double ans;
   if (intersect(a, b, u, v))
      ans = 0;
   else
      ans = min({pointRayDist(a, u, v), pointRayDist(u, a, b)});
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