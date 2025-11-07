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
   set<pii> s;
   int curr;
   for (int i = 0; i < k; i++) {
      cin >> curr;
      q.push_front(curr);
      auto f = m.find(curr);
      if (f != m.end())
         s.erase({-f->second, curr}), s.emplace(-f->second - 1, curr);
      else
         s.emplace(-1, curr);
      m[curr]++;
   }

   // for (auto [k, v] : s) cout << k << " " << v << "\n";
   cout << s.begin()->second << "\n";
   for (int i = k; i < n; i++) {
      cin >> curr;
      auto f = m.find(curr);
      if (f != m.end())
         s.erase({-f->second, curr}), s.emplace(-f->second - 1, curr);
      else
         s.emplace(-1, curr);
      m[curr]++;
      q.push_front(curr);
      f = m.find(q.back());
      if (f->second > 1)
         s.erase({-f->second, q.back()}), s.emplace(-f->second + 1, q.back()),
             m[q.back()]--;
      else
         s.erase({-f->second, q.back()}), m.erase(q.back());
      q.pop_back();
      // for (auto [k, v] : s) cout << k << " " << v << "\n";
      cout << s.begin()->second << "\n";
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