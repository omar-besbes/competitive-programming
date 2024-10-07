#include <bits/stdc++.h>

using namespace std;

string s[1000];
int n, m, nb;

void propagate(int x, int y) {
   if (x < 0 || y < 0 || x >= n || y >= m || s[x][y] == '#') return;
   s[x][y] = '#';
   propagate(x + 1, y);
   propagate(x - 1, y);
   propagate(x, y - 1);
   propagate(x, y + 1);
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);

   cin >> n >> m;
   for (int i = 0; i < n; ++i) cin >> s[i];
   nb = 0;
   for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
         if (s[i][j] == '.') propagate(i, j), nb++;
      }
   }
   cout << nb;

   return 0;
}