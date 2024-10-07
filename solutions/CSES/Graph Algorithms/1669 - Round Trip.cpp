#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<bool> visited, v;
vector<vector<int>> adj;
queue<int> cycle;

bool find_cycle(int index, int lastIndex) {
   bool foundCycle = visited[index];
   v[index] = true;
   visited[index] = true;
   for (auto i = adj[index].begin(); !foundCycle && i != adj[index].end();
        i++) {
      if (*i != lastIndex) foundCycle |= find_cycle(*i, index);
   }
   visited[index] = false;
   if (foundCycle) {
      cycle.push(index);
      return true;
   } else {
      return false;
   }
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);

   cin >> n >> m;
   visited.resize(n + 1, false);
   v.resize(n + 1, false);
   adj.resize(n + 1, vector<int>(0));

   for (int i = 0; i < m; ++i) {
      int a, b;
      cin >> a >> b;
      adj[a].push_back(b);
      adj[b].push_back(a);
   }

   bool test = false;
   for (int i = 0; !test && i < n; ++i) {
      if (!v[i + 1]) test |= find_cycle(i + 1, -1);
   }

   if (!test)
      cout << "IMPOSSIBLE\n";
   else {
      stack<int> tmp;
      int stop = cycle.front();
      tmp.push(stop);
      cycle.pop();
      while (!cycle.empty()) {
         tmp.push(cycle.front());
         if (stop == cycle.front()) break;
         cycle.pop();
      }
      cout << tmp.size() << "\n";
      while (!tmp.empty()) {
         cout << tmp.top() << " ";
         tmp.pop();
      }
   }

   return 0;
}