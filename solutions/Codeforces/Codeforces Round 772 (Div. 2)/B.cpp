#include <bits/stdc++.h>
using namespace std;

int main() {
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w+", stdout);

   int t;
   cin >> t;
   while (t--) {
      int n;
      cin >> n;
      vector<int> a(n);
      int op = 0;
      vector<int> maxi;

      for (int i = 0; i < n; ++i) {
         cin >> a[i];
      }

      for (int i = 1; i < n - 1; ++i) {
         if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
            maxi.push_back(i);
         }
      }

      for (size_t i = 0; i + 1 < maxi.size(); i += 2) {
         int filler = max(a[maxi[i]], a[maxi[i + 1]]);
         for (int j = maxi[i] + 1; j < maxi[i + 1]; ++j) {
            if (a[j] - filler)
               a[j] = filler;
            else
               op--;
         }
         op += maxi[i + 1] - (maxi[i] + 1);
      }

      cout << op << "\n";
      for (int i = 0; i < n; ++i) {
         cout << a[i] << " ";
      }
      cout << "\n";
   }

   return 0;
}
