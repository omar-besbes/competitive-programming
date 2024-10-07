#include "bits/stdc++.h"
using namespace std;

int n, root, t;
vector<vector<int>> grid, isNode;
vector<tuple<int, int, int>> arr;
vector<int> euler_path, euler_distance, p, visited, first_appearance;
vector<long long> seg;

void build_seg_tree(int v = 1, int l = 0, int r = t - 1) {
   if (l == r) {
      seg[v] = euler_distance[l];
   } else {
      int m = (l + r) / 2;
      build_seg_tree(2 * v, l, m);
      build_seg_tree(2 * v + 1, m + 1, r);
      seg[v] = seg[2 * v] + seg[2 * v + 1];
   }
}

long long query(pair<int, int> range, int v = 1, int l = 0, int r = t - 1) {
   if (range.first > range.second) return 0;
   if (range.first > r || range.second < l) return 0;
   if (range.first == l && range.second == r) return seg[v];
   int m = (l + r) / 2;
   auto left = query(make_pair(range.first, min(range.second, m)), 2 * v, l, m);
   auto right = query(make_pair(max(m + 1, range.first), range.second),
                      2 * v + 1, m + 1, r);
   return left + right;
}

void build_tree(int v, int d = 0) {
   visited[v] = 1;
   euler_path.push_back(v);
   first_appearance[v] = euler_path.size() - 1;
   bool hasChildren = false;
   for (int i = 0; i < n; i++) {
      if (i != v && isNode[i][v] && !visited[i])
         build_tree(i, d + 1), hasChildren = true;
   }
   if (hasChildren) euler_path.push_back(v);
}

bool check_tree() {
   for (int i = 1; i < euler_path.size(); i++)
      euler_distance.push_back(grid[euler_path[i]][euler_path[i - 1]]);
   t = euler_distance.size();
   seg.resize(4 * t);
   build_seg_tree();
   for (int k = n - 1; k < arr.size(); k++) {
      int i = first_appearance[get<1>(arr[k])],
          j = first_appearance[get<2>(arr[k])], d = get<0>(arr[k]);
      if (i > j) swap(i, j);
      if (query(make_pair(i, j - 1)) != d) return false;
   }
   return true;
}

int main() {
   cin >> n;
   bool is_tree = true;
   grid.assign(n, vector<int>(n));
   isNode.assign(n, vector<int>(n, 0));
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
         cin >> grid[i][j];
         if (is_tree) {
            if (i == j)
               is_tree &= grid[i][j] == 0;
            else if (i > j) {
               is_tree &= grid[i][j] == grid[j][i];
               if (grid[i][j]) arr.emplace_back(grid[i][j], i, j);
            }
         }
      }
   }

   sort(arr.begin(), arr.end());

   if (n == 1) {
      cout << (grid[0][0] ? "NO\n" : "YES\n");
   } else if (!is_tree || arr.size() < n - 1) {
      cout << "NO\n";
   } else {
      root = get<1>(arr[0]);
      visited.assign(n, 0);
      first_appearance.assign(n, 0);
      for (int k = 0; k < n - 1; k++) {
         int i = get<1>(arr[k]), j = get<2>(arr[k]);
         isNode[i][j] = isNode[j][i] = 1;
      }
      build_tree(root);
      bool ans = check_tree();
      cout << (ans ? "YES\n" : "NO\n");
   }
}