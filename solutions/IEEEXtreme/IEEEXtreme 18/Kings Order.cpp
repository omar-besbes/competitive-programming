#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m;
vector<set<int>> deps;
vector<vector<int>> children;
vector<ll> id;
vector<bool> vis, visCycle;

const ll mod = 1e9 + 7;

bool find_cycle(int v) {
   if (visCycle[v]) return true;
   vis[v] = true;
   visCycle[v] = true;
   auto ans = false;
   for (auto child : children[v]) ans |= find_cycle(child);
   visCycle[v] = false;
   return ans;
}

int main() {
   cin >> n >> m;
   deps.resize(n), id.resize(n), children.resize(n);
   visCycle.assign(n, false), vis.assign(n, false);
   for (int i = 0; i < n; i++) {
      cin >> id[i];
      id[i] *= mod;
      id[i] += i;
   }

   for (int i = 0; i < m; i++) {
      int a, b;
      cin >> a >> b;
      a--, b--;
      deps[b].insert(a);
      children[a].push_back(b);
   }

   bool has_cycle = false;
   set<ll> roots;
   for (int i = 0; !has_cycle && i < n; i++) {
      if (!vis[i]) has_cycle = find_cycle(i);
      if (deps[i].empty()) roots.insert(id[i]);
   }
   if (has_cycle) {
      cout << -1 << "\n";
      return 0;
   }

   while (!roots.empty()) {
      auto _id = *roots.begin();
      int idx = _id % mod;
      cout << idx + 1 << " ";
      roots.erase(roots.begin());

      for (auto child : children[idx]) {
         deps[child].erase(idx);
         if (deps[child].empty()) roots.insert(id[child]);
      }
   }
}