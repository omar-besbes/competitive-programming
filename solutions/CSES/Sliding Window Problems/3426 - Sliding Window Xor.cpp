#include <bits/stdc++.h>
using namespace std;
#define input "input.in"
#define output "output.out"

#define int long long

void solve() {
   int n, k;
   cin >> n >> k;
   int x, a, b, c;
   cin >> x >> a >> b >> c;

   deque<int> q{x};
   int curr = x, sum = x;
   for (int i = 1; i < k; i++) {
      q.push_front((a * q.front() + b) % c);
      sum = sum ^ q.front();
   }

   int res = sum;
   for (int i = k; i < n; i++) {
      q.push_front((a * q.front() + b) % c);
      sum = sum ^ q.front();
      sum = sum ^ q.back();
      q.pop_back();
      res = res ^ sum;
   }

   cout << "\n" << res << "\n";
}

int32_t main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);

   if (fopen(input, "r")) freopen(input, "r", stdin);
   if (fopen(output, "r")) freopen(output, "w+", stdout);

   int t = 1;
   // cin >> t;
   while (t--) solve();
}