#include <bits/stdc++.h>
using namespace std;

void solve() {
   int n;
   cin >> n;
   long long maxi = 0, mini = INT_MAX;
   for (int i = 0; i < n; i++) {
      long long x;
      cin >> x;
      maxi = max(maxi, x);
      mini = min(mini, x);
   }

   auto score = (n - 1) * (maxi - mini);
   cout << score << "\n";
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);

   int t = 1;
   cin >> t;
   while (t--) solve();
}