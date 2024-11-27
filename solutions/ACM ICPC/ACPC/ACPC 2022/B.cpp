#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef long long ll;

struct P {
   ll x, y;
   P operator+(P p) const { return P{x + p.x, y + p.y}; }
   P operator-(P p) const { return P{x - p.x, y - p.y}; }
   ll dot(P p) const { return x * p.x + y * p.y; }
   ll cross(P p) const { return x * p.y - y * p.x; }
   bool between(P a, P b, P c, P d, bool strict) {
      auto s1 = (d - c).cross(*this - c);
      auto s2 = (a - b).cross(*this - b);
      if (strict) return s1 && s2 && ((s1 < 0) ^ (s2 < 0));
      return (s1 == 0) || (s2 == 0) || ((s1 < 0) ^ (s2 < 0));
   }
};

const ll mod = 1e9 + 7;

void solve() {
   int n;
   cin >> n;
   vector<P> p(n);
   vector<ll> keys;

   auto key = [](P &p) {
      auto [x, y] = p;
      return (x + 1e6) + (y + 1e6) * mod;
   };

   for (auto &i : p) {
      cin >> i.x >> i.y;
      keys.push_back(key(i));
   }

   sort(all(p), [&](auto x, auto y) { return key(x) <= key(y); });
   sort(all(keys));

   auto cnt = [&](int a, int b, int c, int d) {
      int ans = 0;
      for (int i = 0; i < n; i++) {
         if (i == a || i == b || i == c || i == d) continue;
         if (p[i].between(p[a], p[b], p[c], p[d], true)) {
            auto s1 = (p[i] - p[b]).cross(p[c] - p[b]);
            auto s2 = (p[d] - p[b]).cross(p[c] - p[b]);
            if (s1 && s2 && ((s1 < 0) ^ (s2 < 0))) {
               // cout << a << " " << b << " " << c << " " << d << " " << i <<
               // endl;
               ans++;
            }
         }
      }
      return ans;
   };

   int res = 0;
   for (int k = 0; k < n; k++) {
      for (int i = k + 1; i < n; i++) {
         for (int j = i + 1; j < n; j++) {
            auto a = p[k], b = p[i], c = p[j];
            if ((a - b).dot(c - b) != 0 || (a - b).cross(c - b) == 0) continue;

            /**
             * A ---------- D
             * |            |
             * |            |
             * B ---------- C
             */

            auto d = a + (c - b);  // OD = OB + BD = OB + BA + BC = OA + BC
            assert((b - a).dot(d - a) == 0);
            auto it = lower_bound(all(keys), key(d));
            if (it == keys.end() || *it != key(d)) continue;
            int idx = it - keys.begin();

            // cout << "(" << a.x << "," << a.y << ") (" << b.x << "," << b.y
            //      << ") (" << c.x << "," << c.y << ") => (" << d.x << "," <<
            //      d.y
            //      << ")" << endl;
            // cout << k << " " << i << " " << j << " " << idx << endl;

            res += cnt(k, i, j, idx);
            res += cnt(j, idx, k, i);
         }
      }
   }

   cout << res << endl;
}

signed main() {
   ios::sync_with_stdio(false);
   cin.tie(0);

   int tt = 1;
   cin >> tt;
   while (tt--) {
      solve();
   }
}