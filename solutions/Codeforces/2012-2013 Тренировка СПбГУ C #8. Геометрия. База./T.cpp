#include <bits/stdc++.h>
using namespace std;
#define input "raydist.in"
#define output "raydist.out"

const double EPS = 1e-6;

template <class T>
struct Point {
   typedef Point P;
   T x, y;
   Point(T x = 0, T y = 0) : x(x), y(y) {}
   bool operator==(P p) const {
      return abs(x - p.x) <= EPS && abs(y - p.y) <= EPS;
   }
   P operator+(P p) const { return P(x + p.x, y + p.y); }
   P operator-(P p) const { return P(x - p.x, y - p.y); }
   P operator*(T d) const { return P(x * d, y * d); }
   P operator/(T d) const { return P(x / d, y / d); }
   T dot(P p) const { return x * p.x + y * p.y; }
   T dot(P a, P b) const { return (a - *this).dot(b - *this); }
   T cross(P p) const { return x * p.y - y * p.x; }
   T cross(P a, P b) const { return (a - *this).cross(b - *this); }
   T dist2() const { return x * x + y * y; }
   double dist() const { return sqrt((double)dist2()); }
   // angle to x-axis in interval [-pi, pi]
   double angle() const { return atan2(y, x); }
   P unit() const { return *this / dist(); }  // makes dist()=1
   P perp() const { return P(-y, x); }        // rotates +90 degrees
   P normal() const { return perp().unit(); }
   // returns point rotated 'a' radians ccw around the origin
   P rotate(double a) const {
      return P(x * cos(a) - y * sin(a), x * sin(a) + y * cos(a));
   }
   friend istream &operator>>(istream &os, P &p) { return os >> p.x >> p.y; }
   friend ostream &operator<<(ostream &os, P p) {
      return os << "(" << p.x << "," << p.y << ")";
   }
   bool between(P b, P c) {
      P bl(min(b.x, c.x), min(b.y, c.y)), tr(max(b.x, c.x), max(b.y, c.y));
      return x >= bl.x && x <= tr.x && y >= bl.y && y <= tr.y;
   }
};

template <class T>
struct Line {
   using P = Point<T>;
   using L = Line;
   T a, b, c;
   Line() : a(0), b(0), c(0) {}
   Line(P u, P v) {
      a = u.y - v.y;
      b = v.x - u.x;
      c = -a * u.x - b * u.y;
      auto g = sqrt(a * a + b * b);
      assert(abs(g) > EPS);
      a /= g, b /= g, c /= g;
      if (a < -EPS || (abs(a) <= EPS && b < -EPS)) a *= -1, b *= -1, c *= -1;
   }
   Line(T a, T b, T c) : a(a), b(b), c(c) {}
   bool colinear(L &l) { return abs(a * l.b - b * l.a) <= EPS; }
   double dist(P &p) { return (a * p.x + b * p.y + c) / sqrt(a * a + b * b); }
   P intersection(L &l) {
      auto v1 = P{a, l.a};
      auto v2 = P{b, l.b};
      auto v3 = P{c, l.c};
      // make sure T is double
      P p = {-v3.cross(v2) / v1.cross(v2), -v1.cross(v3) / v1.cross(v2)};
      return p;
   }
};

template <class T>
struct Ray {
   using P = Point<T>;
   using L = Line<T>;
   using R = Ray;
   P p1, p2;  // ray from p1 to p2
   L l;

   Ray(P p1, P p2) : p1(p1), p2(p2), l(p1, p2) {}

   double dist(P x) {
      if (p1.dot(p2, x) <= EPS) {
         return (p1 - x).dist();
      } else {
         auto [a, b, c] = l;
         return abs(a * x.x + b * x.y + c) / sqrt(a * a + b * b);
      }
   }

   bool intersect(R &r) {
      if (abs((p1 - p2).cross(r.p1, r.p2)) <= EPS) {
         if (abs(l.c - r.l.c) > EPS) return false;
         return p1.dot(p2, r.p1) >= -EPS || r.p1.dot(r.p1, p1) >= -EPS;
      } else {
         auto i = l.intersection(r.l);
         return p1.dot(i, p2) >= -EPS && r.p1.dot(i, r.p2) >= -EPS;
      }
   }

   double dist(R r) {
      if (intersect(r)) return 0;
      return min(dist(r.p1), r.dist(p1));
   }
};

using P = Point<double>;
using L = Line<double>;
using R = Ray<double>;

void solve() {
   P a, b, u, v;
   cin >> a >> b >> u >> v;
   auto ans = R(a, b).dist(R(u, v));
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
