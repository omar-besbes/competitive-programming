#include <bits/stdc++.h>
using namespace std;

long long ans = 0;

void subproblem(vector<int>::iterator s, vector<int>::iterator e,
                long long goal, unordered_map<int, long long> &miss) {
   int n = e - s;
   for (int mask = 1; mask < (1 << n); mask++) {
      long long sum = 0;
      for (int j = 0; j < n; j++) sum += mask & (1 << j) ? *(s + j) : 0;

      if (sum == goal)
         ans++;
      else if (sum < goal)
         miss[sum]++;
   }
}

void solve() {
   int n, x;
   cin >> n >> x;
   vector<int> t(n);
   for (auto &i : t) cin >> i;
   sort(t.begin(), t.end());

   int m = n / 2;
   unordered_map<int, long long> mp1, mp2;
   subproblem(t.begin(), t.begin() + m, x, mp1);
   subproblem(t.begin() + m, t.end(), x, mp2);

   for (auto [sum, v] : mp1) {
      if (mp2.find(x - sum) != mp2.end()) ans += v * mp2[x - sum];
   }

   cout << ans << "\n";
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);

   int t = 1;
   // cin >> t;
   while (t--) solve();
}