#include <bits/stdc++.h>

#include <algorithm>
using namespace std;
#define input "input.in"
#define output "output.out"

array<array<int, 8>, 8> g;
set<int> bannedx, bannedy;
set<pair<int, int>> bannedslope;
int ans = 0;

void dfs(int i) {
   if (i >= 8) {
      ans++;
      return;
   }

   if (bannedx.find(i) != bannedx.end()) return;
   for (int j = 0; j < 8; j++) {
      if (g[i][j]) continue;
      if (bannedy.find(j) != bannedy.end()) continue;
      if (find_if(bannedslope.begin(), bannedslope.end(), [i, j](auto q) {
             auto [qx, qy] = q;
             return abs(qx - i) == abs(qy - j);
          }) != bannedslope.end())
         continue;

      bannedy.insert(j);
      bannedx.insert(i);
      bannedslope.insert(make_pair(i, j));
      dfs(i + 1);
      bannedy.erase(j);
      bannedx.erase(i);
      bannedslope.erase(make_pair(i, j));
   }
}

void solve() {
   for (auto& i : g) {
      string s;
      cin >> s;
      for (int j = 0; j < s.length(); j++) {
         auto c = s[j];
         if (c == '.')
            i[j] = 0;
         else
            i[j] = 1;
      }
   }

   dfs(0);
   cout << ans;
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
