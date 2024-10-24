#include <bits/stdc++.h>
using namespace std;

void solve() {
   int n;
   cin >> n;
   vector<int> a(n);
   for (auto &i : a) cin >> i;
   int ans = a[0] == 0;
   long long sum = a[0];
   set<int> seen;
   seen.insert(a[0]);
   seen.insert(0);
   for (int i = 1; i < n; i++) {
      sum += a[i];
      if (seen.count(sum))
         ans++, sum = 0, seen.clear(), seen.insert(0);
      else
         seen.insert(sum);
   };
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