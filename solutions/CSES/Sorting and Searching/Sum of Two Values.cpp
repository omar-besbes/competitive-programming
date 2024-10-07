#include <bits/stdc++.h>
using namespace std;

int main() {
   int n, x;
   cin >> n >> x;
   vector<pair<int, int>> a(n);
   for (int i = 0; i < n; i++) {
      cin >> a[i].first;
      a[i].second = i;
   }

   sort(a.begin(), a.end());

   auto bs = [&](int val) {
      int l = 0, r = n - 1;
      while (l <= r) {
         int m = (r + l) / 2;
         if (a[m].first > val)
            r = m - 1;
         else if (a[m].first < val)
            l = m + 1;
         else
            return m;
      }
      return -1;
   };

   for (int i = 0; i < n; i++) {
      int j = bs(x - a[i].first);
      if (i != j && j != -1) {
         cout << 1 + a[i].second << " " << 1 + a[j].second;
         return 0;
      }
   }

   cout << "IMPOSSIBLE";
}