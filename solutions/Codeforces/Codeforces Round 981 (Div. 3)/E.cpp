#include <bits/stdc++.h>
using namespace std;

void solve() {
   int n;
   cin >> n;
   vector<int> a(n);
   for (auto &i : a) {
      cin >> i;
      i--;
   }

   vector<int> vis(n, false);
   int d = 0, ans = 0;
   for (int i = 0; i < n; i++) {
      int j = i;
      while (!vis[j]) {
         vis[j] = true;
         d++;
         j = a[j];
      }
      ans += max(0, (d - 1) / 2);
      d = 0;
   }

   cout << ans << "\n";
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);

   int t = 1;
   cin >> t;
   while (t--) solve();
}