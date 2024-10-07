#include "bits/stdc++.h"
using namespace std;

void solve() {
   int n, m, k;
   cin >> n >> m >> k;
   vector<pair<int, int>> a(n);
   for (int i = 0; i < n; i++) {
      int tmp;
      cin >> tmp;
      a[i] = make_pair(tmp, i);
   }

   sort(a.begin(), a.end());

   long long ans = LONG_LONG_MAX;
   int d = (k / m) + (k % m == 0 ? 0 : 1);
   int leftover = k % m == 0 ? m : k - (k / m) * m;

   int i = a[d - 1].second;
   sort(a.begin(), a.begin() + d,
        [](auto &l, auto &r) { return l.second < r.second; });
   for (int j = 0; j < d; j++)
      if (a[j].second == i) {
         i = j;
         break;
      }

   long long tmp = 0;
   long long cur = 0;
   for (auto j = 0; j < d; j++) {
      int q = (j == i ? leftover : m);
      tmp += (cur + a[j].first) * q;
      cur += q;
   }
   ans = min(ans, tmp);

   cout << ans << "\n";
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);

   int t;
   cin >> t;
   while (t--) solve();
}