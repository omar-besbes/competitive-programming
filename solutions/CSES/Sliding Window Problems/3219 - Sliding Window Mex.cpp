#include <bits/stdc++.h>
using namespace std;
#define input "input.in"
#define output "output.out"

#define ll long long
#define int ll
#define pii pair<int, int>

void solve() {
   int n, k;
   cin >> n >> k;

   deque<int> q;
   map<int, int> m;
   bitset<(int)1e9 + 5> b;
   b.set();
   int curr;
   for (int i = 0; i < k; i++) {
      cin >> curr;
      q.push_front(curr);
      m[curr]++;
      b.reset(curr);
   }

   // for (auto [k, v] : m) cout << k << " " << v << "\n";
   cout << b._Find_first() << "\n";
   for (int i = k; i < n; i++) {
      cin >> curr;
      m[curr]++;
      b.reset(curr);
      q.push_front(curr);
      auto f = m.find(q.back());
      if (f->second > 1)
         m[q.back()]--;
      else
         m.erase(q.back()), b.set(q.back());
      q.pop_back();
      // for (auto [k, v] : m) cout << k << " " << v << "\n";
      cout << b._Find_first() << "\n";
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