#include <bits/stdc++.h>
using namespace std;

void solve() {
   int n;
   cin >> n;
   vector<tuple<int, int, int>> a(n);
   vector<pair<int, int>> ans(n);
   vector<int> suff(n + 1), pref(n + 1);

   for (int i = 0; i < n; i++) {
      int f, s;
      cin >> f >> s;
      a[i] = {f, s, i};
   }

   sort(a.begin(), a.end(), [](auto x, auto y) {
      auto [fx, sx, tx] = x;
      auto [fy, sy, ty] = y;
      if (sx == sy) return fx < fy;
      return sx > sy;
   });

   for (int i = n - 1; i >= 0; i--) suff[i] = max(suff[i + 1], get<0>(a[i]));
   pref[0] = suff[0] + 1;
   for (int i = 0; i < n; i++) pref[i + 1] = min(pref[i], get<0>(a[i]));

   for (int i = 0; i < n; i++) {
      auto [f, s, t] = a[i];
      ans[t].first = f <= suff[i + 1] ? 1 : 0;
      ans[t].second = f >= pref[i] ? 1 : 0;
   }

   for (auto [f, s] : ans) cout << f << " ";
   cout << "\n";
   for (auto [f, s] : ans) cout << s << " ";
   cout << "\n";
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);

   int t = 1;
   // cin >> t;
   while (t--) solve();
}

/**
 *
4 8
1 6
3 6
2 4
 *
 *
 */