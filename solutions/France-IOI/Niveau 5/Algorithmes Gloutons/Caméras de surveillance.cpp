#include <bits/stdc++.h>
using namespace std;

template <class U>
void merge(set<U> &a, set<U> &b) {
   for(auto &i: b) a.insert(i);
   b.clear();
}

typedef tuple<int, int, int> edge;

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);

   int n, a;
   cin >> n >> a;
   vector<set<tuple<int, int, int>>> adj(n, set<tuple<int, int, int>>());
   for (int i = 0; i < a; i++) {
      int a, b, w;
      cin >> a >> b >> w;
      a--, b--;
      adj[a].insert(make_tuple(w, a, b));
      adj[b].insert(make_tuple(w, b, a));
   }

   vector<bool> selected(n, false);
   set<edge> mst;

   int ans = 0, nb = 1;
   selected[0] = true;
   set<edge> q;
   merge(q, adj[0]);

   while (nb < n) {
      int w, a, b;
      auto e = *q.begin();
      tie(w, a, b) = e;
      q.erase(make_tuple(w, b, a));
      q.erase(make_tuple(w, a, b));

      if (selected[a] && selected[b]) continue;
      if (!selected[a]) selected[a] = true, merge<edge>(q, adj[a]);
      if (!selected[b]) selected[b] = true, merge<edge>(q, adj[b]);

      mst.insert(e);
      ans += w;
      nb++;
   }

   cout << ans << "\n";
}