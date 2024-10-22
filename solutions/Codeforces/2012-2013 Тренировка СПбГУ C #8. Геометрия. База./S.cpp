#include <bits/stdc++.h>
using namespace std;
#define input "position.in"
#define output "position.out"

struct P {
   double x, y;
   void read() { cin >> x >> y; }
};

struct L {
   double a, b, c;
   void read() { cin >> a >> b >> c; }
   double eval(P p) const { return a * p.x + b * p.y + c; }
};

void solve() {
   P p, q;
   p.read(), q.read();
   L l;
   l.read();
   auto pos1 = l.eval(p);
   auto pos2 = l.eval(q);
   auto ans = pos1 * pos2;
   cout << (ans > 0 ? "YES" : "NO");
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