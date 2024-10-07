#include <bits/stdc++.h>
using namespace std;

void solve() {
   int n;
   cin >> n;
   vector<tuple<int, int, int>> a(2 * n);
   vector<int> ans(n);

   for (int i = 0; i < 2 * n; i += 2) {
      int f, s;
      cin >> f >> s;
      a[i] = {f, i / 2, 1};
      a[i + 1] = {s, i / 2, -1};
   }

   sort(a.begin(), a.end(), [](auto a, auto b) {
      auto [fa, sa, ta] = a;
      auto [fb, sb, tb] = b;
      if (fa == fb) return ta > tb;
      return fa < fb;
   });

   auto res = 0;
   queue<int> indicies;
   for (int i = 0; i < 2 * n; i++) {
      auto [f, s, t] = a[i];
      if (t > 0) {
         if (!indicies.empty()) {
            ans[s] = indicies.front();
            indicies.pop();
         } else {
            res++;
            ans[s] = res;
         }
      } else
         indicies.push(ans[s]);
   }

   cout << res << "\n";
   for (auto &i : ans) cout << i << " ";
   cout << "\n";
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);

   int t = 1;
   // cin >> t;
   while (t--) solve();
}
