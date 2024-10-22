#include <bits/stdc++.h>
using namespace std;
#define input "point1.in"
#define output "point1.out"
typedef long long ll;

struct P {
   ll x, y;
   void read() { cin >> x >> y; }
};

struct L {
   ll a, b, c;
   void read() { cin >> a >> b >> c; }
   bool has(P p) { return a * p.x + b * p.y + c == 0; }
};

void solve() {
   P p;
   p.read();
   L l;
   l.read();
   cout << (l.has(p) ? "YES" : "NO");
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