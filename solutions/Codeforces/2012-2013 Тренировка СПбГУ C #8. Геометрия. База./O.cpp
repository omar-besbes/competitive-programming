#include <bits/stdc++.h>
using namespace std;
#define input "line3.in"
#define output "line3.out"
typedef long long ll;

struct P {
   ll x, y;
   void read() { cin >> x >> y; }
};

struct L {
   ll a, b, c;
   void read() { cin >> a >> b >> c; }
};

void solve() {
   L l;
   l.read();
   auto [a, b, c] = l;
   ll r;
   cin >> r;
   cout << fixed << setprecision(10);
   cout << a << " " << b << " " << c + r * sqrt(a * a + b * b) << "\n";
   cout << a << " " << b << " " << c - r * sqrt(a * a + b * b) << "\n";
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