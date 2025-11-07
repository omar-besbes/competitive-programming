#include <bits/stdc++.h>
using namespace std;
#define input "input.in"
#define output "output.out"

#define int long long
#define pii pair<int, int>

void solve() {
   int n, k;
   cin >> n >> k;
   int x, a, b, c;
   cin >> x >> a >> b >> c;

   // incresing minimums
   deque<pii> q;
   q.emplace_front(x, 0);
   int curr = x;
   int res = 0;
   for (int i = 0; i < n; i++) {
      curr = i == 0 ? x : ((a * curr + b) % c);

      // push new element
      while (!q.empty() && q.front().first >= curr) q.pop_front();
      q.emplace_front(curr, i);

      // pop last element
      if (q.back().second == i - k) q.pop_back();

      // if (i >= k - 1) cout << "new min: " << q.back().first << "\n";
      if (i >= k - 1) res = res ^ q.back().first;
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