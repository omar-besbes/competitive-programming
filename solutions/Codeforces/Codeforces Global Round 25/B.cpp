#include "bits/stdc++.h"
using namespace std;

void solve() {
   int n, k;
   cin >> n >> k;
   k--;
   vector<int> r(n), maxi(n + 1, 0);
   for (int i = 0; i < n; i++) {
      cin >> r[i];
      maxi[i + 1] = max(maxi[i], r[i]);
   }
   vector<int> p;
   for (int i = 0; i < n; i++)
      if (r[i] > r[k]) p.push_back(i);
   p.push_back(n);

   int ans = count(maxi.begin() + 2, maxi.end(), r[k]);

   if (p.size() > 1) {
      ans = max(ans, p[0] - 1);
      ans = max(ans, min(k, p[1]) - p[0] - 1 + (p[0] == 0 ? 0 : 1));
   } else {
      ans = n - 1;
   }

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