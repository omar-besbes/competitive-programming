#include <bits/stdc++.h>
using namespace std;
#define input "distance1.in"
#define output "distance1.out"

struct P {
   double x, y;
   void read() { cin >> x >> y; }
};

void solve() {
   P x;
   x.read();
   double a, b, c;
   cin >> a >> b >> c;
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