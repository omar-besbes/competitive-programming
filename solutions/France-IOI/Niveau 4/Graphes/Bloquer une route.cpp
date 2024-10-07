#include "bits/stdc++.h"

using namespace std;

int n, m, timer = 0;
vector<set<int>> adj;
vector<bool> visited;
vector<int> tin, low;
set<pair<int, int>> bridges;

void dfs(int v, int p = -1) {
   visited[v] = true;
   tin[v] = low[v] = timer++;
   for (int to : adj[v]) {
      if (to == p) continue;
      if (visited[to]) {
         low[v] = min(low[v], tin[to]);
      } else {
         dfs(to, v);
         low[v] = min(low[v], low[to]);
         if (low[to] > tin[v]) {
            if (v < to)
               bridges.insert(make_pair(v + 1, to + 1));
            else
               bridges.insert(make_pair(to + 1, v + 1));
         }
      }
   }
}

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);

   cin >> n >> m;
   timer = 0;
   visited.assign(n, false);
   adj.assign(n, set<int>());
   tin.assign(n, -1);
   low.assign(n, -1);

   for (int i = 0; i < m; ++i) {
      int x, y;
      cin >> x >> y;
      (adj)[x - 1].insert(y - 1);
      (adj)[y - 1].insert(x - 1);
   }

   for (int i = 0; i < n; ++i) {
      if (!visited[i]) dfs(i);
   }

   cout << bridges.size() << "\n";
   for (const auto &item : bridges) {
      cout << item.first << " " << item.second << "\n";
   }
}