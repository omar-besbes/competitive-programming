#include "bits/stdc++.h"
using namespace std;

void solve() {
   int n;
   cin >> n;
   vector<int> ans;
   for (int i = 0; i < n; i++) {
      string s;
      cin >> s;
      ans.push_back(s.find('#') + 1);
   }

   reverse(ans.begin(), ans.end());

   for (auto i : ans) cout << i << " ";
   cout << "\n";
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);

   int t = 1;
   cin >> t;
   while (t--) solve();
}