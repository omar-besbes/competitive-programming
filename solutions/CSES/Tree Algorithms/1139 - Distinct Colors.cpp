#include "bits/stdc++.h"
using namespace std;

int n;
vector<set<int>> a;
vector<vector<int>> adj;
vector<int> b;

void merge(int v, int last) {
   for (const auto &item : adj[v]) {
      //        auto x = a[item], y = a[v];
      if (item == last) continue;
      merge(item, v);
      if (a[v].size() < a[item].size()) swap(a[v], a[item]);
      a[v].insert(a[item].begin(), a[item].end());
   }
   b[v] = a[v].size();
}

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);

   cin >> n;
   a.assign(n, set<int>());
   b.assign(n, 0);
   adj.assign(n, vector<int>());
   for (int i = 0; i < n; ++i) {
      int x;
      cin >> x;
      a[i].insert(x);
   }

   for (int i = 0; i < (n - 1); ++i) {
      int x, y;
      cin >> x >> y;
      adj[x - 1].push_back(y - 1);
      adj[y - 1].push_back(x - 1);
   }

   merge(0, 0);

   for (int i = 0; i < n; ++i) {
      cout << b[i] << " ";
   }
   cout << "\n";
}