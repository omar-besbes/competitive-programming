#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> a;

void find_furthest_vertex(int v, pair<int, int> &f, vector<bool> &marked,
                          int d = 0) {
   if (marked[v]) return;
   marked[v] = true;
   if (d > f.second) {
      f.second = d;
      f.first = v;
   }
   for (const auto &item : a[v]) {
      find_furthest_vertex(item, f, marked, d + 1);
   }
   marked[v] = false;
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);

   int n;
   cin >> n;
   a.resize(n + 1);
   for (int i = 0; i < n - 1; ++i) {
      int x, y;
      cin >> x >> y;
      a[y].push_back(x);
      a[x].push_back(y);
   }

   pair<int, int> f{1, 0};
   find_furthest_vertex(1, f, *(new vector<bool>(n + 1, false)));
   find_furthest_vertex(f.first, f, *(new vector<bool>(n + 1, false)));
   cout << f.second << "\n";

   return 0;
}