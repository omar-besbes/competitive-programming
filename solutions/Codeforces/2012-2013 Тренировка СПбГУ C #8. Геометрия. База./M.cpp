#include <bits/stdc++.h>
using namespace std;
#define input "line1.in"
#define output "line1.out"
typedef long long ll;

struct P {
   ll x, y;
   void read() { cin >> x >> y; }
};

tuple<ll, ll, ll> getline(P u, P v) {
   ll a = u.y - v.y;
   ll b = v.x - u.x;
   ll c = -a * u.x - b * u.y;
   return {a, b, c};
}

void solve() {
   P p1, p2;
   p1.read(), p2.read();
   auto [a, b, c] = getline(p1, p2);
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