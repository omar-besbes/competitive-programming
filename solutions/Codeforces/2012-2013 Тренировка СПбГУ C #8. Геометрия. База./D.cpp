#include <bits/stdc++.h>
using namespace std;
#define input "area1.in"
#define output "area1.out"
typedef long long ll;

struct P {
   ll x, y;
   void read() { cin >> x >> y; }
   P operator-(const P &p) const { return P{x - p.x, y - p.y}; }
   ll cross(const P &p) { return x * p.y - y * p.x; }
   ll cross(const P &a, const P &b) { return (a - *this).cross(b - *this); }
};

void solve() {
   const int n = 3;
   vector<P> v(n);
   for (auto &p : v) p.read();

   double ans = 0;
   for (int i = 2; i < n; i++) ans += v[0].cross(v[i - 1], v[i]);
   cout << fixed << setprecision(10) << abs(ans) / 2.0;
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