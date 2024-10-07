#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> t;
vector<vector<int>> adj;

int main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);

   cin >> n >> m;
   t.resize(n + 1, 0);
   adj.resize(n + 1, vector<int>(0));

   for (int i = 0; i < m; ++i) {
      int a, b;
      cin >> a >> b;
      adj[a].push_back(b);
      adj[b].push_back(a);
   }

   queue<pair<int, int>> q;
   bool res = true;
   for (int i = 0; res && i < n; ++i) {
      if (!t[i + 1]) {
         q.push(make_pair(i + 1, 1));
         while (res && !q.empty()) {
            auto cur = q.front();
            q.pop();
            if (t[cur.first]) {
               if (cur.second != t[cur.first])
                  res = false;
               else
                  continue;
            } else
               t[cur.first] = cur.second;
            for (const auto &item : adj[cur.first]) {
               q.push(make_pair(item, 3 - cur.second));
            }
         }
      }
   }

   if (res) {
      for (int i = 0; i < n; ++i) cout << t[i + 1] << " ";
      cout << "\n";
   } else {
      cout << "IMPOSSIBLE\n";
   }

   return 0;
}