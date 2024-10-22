#include <bits/stdc++.h>
using namespace std;
#define input "point3.in"
#define output "point3.out"
typedef long long ll;

struct P {
   ll x, y;
   void read() { cin >> x >> y; }
   P operator-(P p) const { return P{x - p.x, y - p.y}; }
   ll dot(P p) const { return x * p.x + y * p.y; }
};

struct L {
   ll a, b, c;
   L(P u, P v) {
      a = u.y - v.y;
      b = v.x - u.x;
      c = -a * u.x - b * u.y;
   }
   void read() { cin >> a >> b >> c; }
   bool has(P p) { return a * p.x + b * p.y + c == 0; }
};

void solve() {
   P p, u, v;
   p.read(), u.read(), v.read();
   auto l = L(u, v);
   cout << (l.has(p) && (v - u).dot(p - u) >= 0 && (u - v).dot(p - v) >= 0
                ? "YES"
                : "NO");
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