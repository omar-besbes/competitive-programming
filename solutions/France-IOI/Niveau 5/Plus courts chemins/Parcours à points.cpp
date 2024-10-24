#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);

   int n, a, s, t;
   cin >> n >> a >> s >> t;
   s--;
   vector<unordered_map<int, int>> adj(n);

   for (int i = 0; i < a; i++) {
      int a, b, d;
      cin >> a >> b >> d;
      adj[a - 1][b - 1] = d;
   }

   vector<int> d(n, INT_MIN), tmp;
   d[s] = 0;
   auto ans = 0;
   while (t--) {
      tmp.assign(n, INT_MIN);
      for (int v = 0; v < n; v++) {
         if (d[v] == INT_MIN) continue;
         for (auto e : adj[v]) {
            int c, w;
            tie(c, w) = e;
            ans = max(ans, d[v] + w);
            tmp[c] = max(tmp[c], d[v] + w);
         }
      }

      d.swap(tmp);
   }

   cout << ans;
}