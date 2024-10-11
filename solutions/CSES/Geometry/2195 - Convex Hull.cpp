#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Po {
   typedef Po P;
   ll x, y, idx;
   Po(ll x = 0, ll y = 0) : x(x), y(y) {}
   bool operator==(P t) const { return x == t.x && y == t.y; }
   P operator-(P p) const { return P(x - p.x, y - p.y); }
   ll cross(P p) const { return x * p.y - y * p.x; }
   ll cross(P a, P b) const { return (a - *this).cross(b - *this); }
   friend ostream &operator<<(ostream &os, P p) {
      return os << p.x << " " << p.y << "\n";
   }
};

void solve() {
   int n;
   cin >> n;
   vector<Po> v(n);
   for (int i = 0; i < n; i++) {
      cin >> v[i].x >> v[i].y;
      v[i].idx = i;
   }

   vector<Po> convex_hull;

   auto getlast2 = [&]() {
      auto x = *(convex_hull.end() - 2), y = *(convex_hull.end() - 1);
      return make_tuple(x, y);
   };

   auto check = [&](Po z) {
      auto [x, y] = getlast2();
      return x.cross(y, z) <= 0;
   };

   // construct upper hull
   sort(v.begin(), v.end(),
        [](Po a, Po b) { return a.x == b.x ? a.y > b.y : a.x < b.x; });
   for (auto cur : v) {
      while (convex_hull.size() >= 2 && !check(cur)) convex_hull.pop_back();
      convex_hull.push_back(cur);
   }

   // construct lower hull
   reverse(v.begin(), v.end());
   convex_hull.pop_back();
   int s = convex_hull.size();
   for (auto cur : v) {
      while (convex_hull.size() - s >= 2 && !check(cur)) convex_hull.pop_back();
      convex_hull.push_back(cur);
   }
   convex_hull.pop_back();

   cout << convex_hull.size() << "\n";
   for (auto i : convex_hull) cout << i;
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);

   int t = 1;
   // cin >> t;
   while (t--) solve();
}