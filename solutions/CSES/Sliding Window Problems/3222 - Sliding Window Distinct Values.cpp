#include <bits/stdc++.h>
using namespace std;
#define input "input.in"
#define output "output.out"

#define int long long

void solve() {
   int n, k;
   cin >> n >> k;

   deque<int> q;
   map<int, int> m;
   int curr;
   for (int i = 0; i < k; i++) {
      cin >> curr;
      q.push_front(curr);
      m[curr]++;
   }

   // for (auto [k, v] : m) cout << k << " " << v << "\n";
   cout << m.size() << "\n";
   for (int i = k; i < n; i++) {
      cin >> curr;
      m[curr]++;
      q.push_front(curr);
      if (m.find(q.back())->second > 1)
         m[q.back()]--;
      else
         m.erase(q.back());
      q.pop_back();
      // for (auto [k, v] : m) cout << k << " " << v << "\n";
      cout << m.size() << "\n";
   }
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