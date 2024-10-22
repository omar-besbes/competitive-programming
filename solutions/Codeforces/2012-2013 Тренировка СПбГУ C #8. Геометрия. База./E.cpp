#include <bits/stdc++.h>
using namespace std;
#define input "bisector.in"
#define output "bisector.out"

struct P {
   double x, y;
   void read() { cin >> x >> y; }
   P operator+(const P &p) const { return P{x + p.x, y + p.y}; }
   P operator-(const P &p) const { return P{x - p.x, y - p.y}; }
   P operator*(double d) const { return P{x * d, y * d}; }
   double dist() { return sqrt(x * x + y * y); }
};

template <typename T>
tuple<T, T, T> getline(P u, P v) {
   T a = u.y - v.y;
   T b = v.x - u.x;
   T c = -a * u.x - b * u.y;
   return {a, b, c};
}

void solve() {
   P x, y, z;
   x.read(), y.read(), z.read();
   y = (y - x), z = (z - x);
   P mid = (y * z.dist() + z * y.dist());
   auto [a, b, c] = getline<double>(x, x + mid);
   cout << fixed << setprecision(10);
   cout << a << " " << b << " " << c;
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