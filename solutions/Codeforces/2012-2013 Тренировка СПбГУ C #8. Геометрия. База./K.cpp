#include <bits/stdc++.h>
using namespace std;
#define input "intersec1.in"
#define output "intersec1.out"
typedef long long ll;

struct P {
   double x, y;
   void read() { cin >> x >> y; }
   P operator-(P p) const { return P{x - p.x, y - p.y}; }
   double cross(P p) const { return x * p.y - y * p.x; }
};

struct L {
   ll a, b, c;
   void read() { cin >> a >> b >> c; }
   P intersection(L l) {
      auto v1 = P{a, l.a};
      auto v2 = P{b, l.b};
      auto v3 = P{c, l.c};
      P p = {-v3.cross(v2) / v1.cross(v2), -v1.cross(v3) / v1.cross(v2)};
      return p;
   }
};

void solve() {
   L l1, l2;
   l1.read(), l2.read();
   auto p = l1.intersection(l2);
   cout << fixed << setprecision(10);
   cout << p.x << " " << p.y;
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