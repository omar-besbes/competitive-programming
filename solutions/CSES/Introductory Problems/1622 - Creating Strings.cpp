#include <bits/stdc++.h>
using namespace std;
#define input "input.in"
#define output "output.out"

void dfs(string s, map<char, int> m) {
   if (m.empty()) {
      cout << s << "\n";
      return;
   }

   map<char, int> m1(m);
   for (auto [k, v] : m1) {
      if (v == 1)
         m.erase(k);
      else
         m[k]--;
      dfs(s + k, m);
      m[k]++;
   }
}

int cnk(int n, int k) {
   int ans = 1, n_k_fact = 1;
   for (auto i = n; i > k; i--) ans *= i;
   for (auto i = n - k; i > 0; i--) n_k_fact *= i;
   return ans / n_k_fact;
}

void solve() {
   string s;
   cin >> s;
   map<char, int> m;
   for (auto c : s) m[c]++;

   int k = 1, rest = s.length();
   for (auto [_, v] : m) {
      k *= cnk(rest, v);
      rest -= v;
   }
   cout << k << "\n";
   dfs("", m);
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);

   if (fopen(input, "r")) freopen(input, "r", stdin);
   if (fopen(output, "r")) freopen(output, "w+", stdout);

   int t = 1;
   // cin >> t;
   while (t--) solve();
}
