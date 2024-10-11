#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct P {
   ll x, y;
   void read() { cin >> x >> y; }
   P operator-(P p) { return P{x - p.x, y - p.y}; }
   ll cross(P p) { return x * p.y - y * p.x; }
   ll cross(P a, P b) { return (a - *this).cross(b - *this); }
};

void solve() {
   int n, m;
   cin >> n >> m;
   vector<P> v(n);
   for (auto &i : v) i.read();

   auto intersect = [](P cur, P p1, P p2) {
      return cur.cross(p1, p2) == 0 &&
             (min(p1.x, p2.x) <= cur.x && max(p1.x, p2.x) >= cur.x) &&
             (min(p1.y, p2.y) <= cur.y && max(p1.y, p2.y) >= cur.y);
   };

   while (m--) {
      P cur;
      cur.read();

      int crossings = 0;
      bool isBoundary = false;
      for (int i = 0; !isBoundary && i < n; i++) {
         auto p1 = v[i], p2 = v[(i + 1) % n];
         if (p1.y > p2.y) swap(p1, p2);

         if (intersect(cur, p1, p2)) {
            isBoundary = true;
         } else {
            auto isTouch = cur.cross(p1, p2) >= 0;
            auto isBetween = (p1.y < cur.y) && (p2.y >= cur.y);
            if (isTouch && isBetween) crossings++;
         }
      }

      if (!isBoundary)
         cout << (crossings & 1 ? "INSIDE\n" : "OUTSIDE\n");
      else
         cout << "BOUNDARY\n";
   }
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);

   int t = 1;
   // cin >> t;
   while (t--) solve();
}