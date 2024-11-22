#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
   ll n;
   cin >> n;
   vector<pair<ll, ll>> v;
   for (int i = 0; i < n; i++) {
      ll a, b;
      cin >> a >> b;
      v.push_back({a, b});
   }
   bool okay = false;
   for (int i = -100; i <= 100; i++) {
      for (int j = -100; j <= 100; j++) {
         bool yess = true;
         for (auto [mo, yo] : v) {
            if ((i >= mo && i <= yo) || (j >= mo && j <= yo)) {
               continue;
            } else
               yess = false;
         }
         if (yess) {
            cout << i << " " << j << endl;
            return;
         }
      }
   }
   cout << -1 << endl;
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);

   int t = 1;
   // cin >> t;
   while (t--) {
      solve();
   }

   return 0;
}