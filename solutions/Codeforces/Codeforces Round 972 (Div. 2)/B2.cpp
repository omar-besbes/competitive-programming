#include <bits/stdc++.h>
using namespace std;

void solve() {
   int n, m, q;
   cin >> n >> m >> q;
   vector<int> b(m);
   for (auto &i : b) cin >> i;
   sort(b.begin(), b.end());

   for (int i = 0; i < q; i++) {
      int pos;
      cin >> pos;
      auto itl = lower_bound(b.begin(), b.end(), pos);
      auto itr = upper_bound(b.begin(), b.end(), pos);
      int l = itl == b.begin() ? -2 * n : *(itl - 1);
      int r = itr == b.end() ? 2 * n : *itr;

      if (itl == b.begin())
         pos = 1;
      else if (itr == b.end())
         pos = n;
      else
         pos = (l + r) / 2;

      cout << min(pos - l, r - pos) << "\n";
   }
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);

   int t = 1;
   cin >> t;
   while (t--) solve();
}