#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
   int n;
   cin >> n;
   vector<string> s;
   vector<vector<int>> v;

   int maxi = 0;
   for (int i = 0; i < n; i++) {
      string cur;
      int val;
      cin >> cur >> val;
      if (!s.empty() && s.back() == cur) {
         v.back().push_back(val);
         maxi = max(maxi, (int)v.back().size());
      } else {
         s.push_back(cur);
         v.push_back({val});
         maxi = max(maxi, (int)v.back().size());
      }
   }

   for (int i = 0; i < maxi; i++) {
      for (int j = 0; j < s.size(); j++)
         if (i < v[j].size()) cout << s[j] << " " << v[j][i] << "\n";
   }
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