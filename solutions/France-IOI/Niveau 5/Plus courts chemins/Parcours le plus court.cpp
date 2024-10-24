#include <bits/stdc++.h>
using namespace std;
#define tiii tuple<int, int, int>

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);

   int n, a, s, f;
   cin >> n >> a >> s >> f;
   s--, f--;
   vector<map<int, int>> adj(n);

   for (int i = 0; i < a; i++) {
      int a, b, d;
      cin >> a >> b >> d;
      adj[a - 1][b - 1] = d;
      adj[b - 1][a - 1] = d;
   }

   vector<int> st(n, INT_MAX), p(n, -1);

   priority_queue<tiii, vector<tiii>, greater<tiii>> q;
   q.push(make_tuple(0, s, s));
   while (!q.empty()) {
      int v, d, pv;
      tie(d, v, pv) = q.top();
      q.pop();

      if (st[v] <= d) continue;
      p[v] = pv;
      st[v] = d;

      for (auto entry : adj[v]) {
         int c, dc;
         tie(c, dc) = entry;
         q.push(make_tuple(d + dc, c, v));
      }
   }

   vector<int> path;
   for (int cur = f; cur != s; cur = p[cur]) path.push_back(cur);
   path.push_back(s);
   reverse(path.begin(), path.end());

   cout << st[f] << " " << path.size() << "\n";
   for (auto i : path) cout << i + 1 << " ";
}