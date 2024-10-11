#include "bits/stdc++.h"
using namespace std;

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);

   int n;
   cin >> n;
   vector<set<int>> a(1);
   for (int i = 0; i < n; ++i) {
      int x;
      cin >> x;
      if (x == 0) {
         a.emplace_back();
      } else {
         a.back().insert(x);
      }
   }
   int res = 0;
   for (const auto &item : a) {
      if (item.size() > res) res = item.size();
   }
   cout << res << "\n";
}