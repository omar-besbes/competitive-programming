#include <bits/stdc++.h>
using namespace std;

int n, m;
pair<vector<int>, bool> v[100000 + 1];
vector<vector<int>> scc;

void call(int city) {
   v[city].second = true;
   for (auto i : v[city].first) {
      if (!v[i].second) {
         scc.back().push_back(i);
         call(i);
      }
   }
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);

   cin >> n >> m;
   for (int i = 0; i < m; ++i) {
      pair<int, int> r;
      cin >> r.first >> r.second;
      v[r.first].first.push_back(r.second);
      v[r.second].first.push_back(r.first);
   }

   for (int i = 1; i <= n; ++i) {
      if (!v[i].second) {
         auto *s = new vector<int>;
         scc.push_back(*s);
         scc.back().push_back(i);
         call(i);
      }
   }

   cout << scc.size() - 1 << "\n";
   for (int i = 1; i < scc.size(); ++i) {
      cout << scc[i][0] << " " << scc[i - 1][0] << "\n";
   }

   return 0;
}