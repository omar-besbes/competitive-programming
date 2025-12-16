#include <bits/stdc++.h>
using namespace std;
#define input "input.in"
#define output "output.out"

pair<int, int> D[] = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2},
                      {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};

vector<vector<int>> g;
queue<tuple<int, int, int>> q;
int n;

void bfs(int i, int j, int c) {
   if (i < 0 || j < 0 || i >= n || j >= n) return;
   if (c >= g[i][j]) return;
   g[i][j] = c;
   for (auto [dx, dy] : D) {
      q.push(make_tuple(i + dx, j + dy, c + 1));
   }
}

void solve() {
   cin >> n;
   g.resize(n, vector<int>(n, n * n));
   q.push(make_tuple(0, 0, 0));
   while (!q.empty()) {
      auto [i, j, c] = q.front();
      q.pop();
      bfs(i, j, c);
   }

   for (auto& i : g) {
      for (auto j : i) {
         cout << j << " ";
      }
      cout << "\n";
   }
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);

   if (fopen(input, "r")) freopen(input, "r", stdin);
   if (fopen(output, "r")) freopen(output, "w+", stdout);

   int t = 1;
   // cin >> t;
   while (t--) solve();
}
