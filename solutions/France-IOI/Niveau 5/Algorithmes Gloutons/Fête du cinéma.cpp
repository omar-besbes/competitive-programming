#include "bits/stdc++.h"
using namespace std;

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);

   int n;
   cin >> n;
   vector<pair<int, int>> s(n);
   for (auto &item : s) cin >> item.first >> item.second;

   sort(s.begin(), s.end(),
        [](pair<int, int> x, pair<int, int> y) { return x.second < y.second; });

   auto ans = 0, cur = 0;
   for (int i = 0; i < n; i++) {
      if (s[i].first >= cur) cur = s[i].second + 1, ans++;
   }

   cout << ans << "\n";
}