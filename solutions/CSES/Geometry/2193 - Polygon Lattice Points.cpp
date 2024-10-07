#include <bits/stdc++.h>
using namespace std;

struct P {
   long long x, y;
   void read() { cin >> x >> y; }
   P operator-(P a) { return P{x - a.x, y - a.y}; }
   long long operator*(P a) { return x * a.y - y * a.x; }
   long long cross(P a, P b) { return (a - *this) * (b - *this); }
};

long long nb_on_segment(P a, P b) {
   long long X = abs((a - b).x), Y = abs((a - b).y);
   if (X == 0) return Y - 1;
   if (Y == 0) return X - 1;
   long long k = X / gcd(X, Y);
   return X / k - 1;
}

void solve() {
   int n;
   cin >> n;
   vector<P> v(n);
   for (auto &i : v) i.read();

   long long double_area = 0;
   for (int y = 1, z = 2; z < n; y++, z++)
      double_area += v[0].cross(v[y], v[z]);
   double_area = abs(double_area);

   long long I = 0, B = n;
   for (int i = 0; i < n; i++) {
      int j = (i - 1 + n) % n;
      B += nb_on_segment(v[i], v[j]);
   }

   I = (double_area + 2 - B) / 2;
   cout << I << " " << B << "\n";
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);

   int t = 1;
   // cin >> t;
   while (t--) solve();
}