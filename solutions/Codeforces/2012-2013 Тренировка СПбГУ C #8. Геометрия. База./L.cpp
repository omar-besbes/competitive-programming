#include <bits/stdc++.h>
using namespace std;
#define input "length.in"
#define output "length.out"
typedef long long ll;

struct P {
   ll x, y;
   void read() { cin >> x >> y; }
   double dist(P p) const {
      return sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y));
   }
};

void solve() {
   P p1, p2;
   p1.read(), p2.read();
   cout << fixed << setprecision(10) << p1.dist(p2);
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