#include <bits/stdc++.h>
using namespace std;

int n, m;
pair<vector<int>, int> v[100000 + 1];
queue<pair<int, int>> q;
stack<int> path;

void bfs(int vertex, int depth) {
   if (v[vertex].second != -1) return;
   v[vertex].second = depth;
   if (vertex == n) {
      while (vertex != 1) {
         for (auto &i : v[vertex].first) {
            if (v[i].second == v[vertex].second - 1) {
               path.push(vertex);
               vertex = i;
            }
         }
      }
      path.push(1);
      while (q.size() > 1) q.pop();
   } else {
      for (auto &i : v[vertex].first) {
         q.push(make_pair(i, depth + 1));
      }
   }
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);

   cin >> n >> m;
   for (int i = 0; i < m; ++i) {
      int a, b;
      cin >> a >> b;
      v[a].first.push_back(b);
      v[b].first.push_back(a);
   }

   for (int i = 1; i <= n; ++i) v[i].second = -1;

   q.push(make_pair(1, 0));
   while (!q.empty()) {
      bfs(q.front().first, q.front().second);
      q.pop();
   }

   if (path.empty()) {
      cout << "IMPOSSIBLE";
   } else {
      cout << path.size() << "\n";
      while (!path.empty()) {
         cout << path.top() << " ";
         path.pop();
      }
   }

   return 0;
}