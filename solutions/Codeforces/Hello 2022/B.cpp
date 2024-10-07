#include <bits/stdc++.h>

using namespace std;

int main() {
   //    ios::sync_with_stdio(false);
   //    cin.tie(nullptr);
   //    cout.tie(nullptr);
   //    freopen("name.in", "r", stdin);
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w+", stdout);

   int t;
   cin >> t;
   while (t--) {
      int n;
      cin >> n;
      int l[n], r[n], c[n];
      for (int i = 0; i < n; ++i) {
         cin >> l[i] >> r[i] >> c[i];
      }
      pair<int, map<int, int>> min = {l[0], {{0, c[0]}}},
                               max = {r[0], {{0, c[0]}}};
      int cost = c[0];
      for (int i = 0; i < n; ++i) {
         // choosing minima and maxima and their indexes
         if (l[i] <= min.first) {
            if (l[i] == min.first)
               min.second[i] = c[i];
            else {
               min.second.clear();
               min.second[i] = c[i];
            }
         }
         if (r[i] >= max.first) {
            if (r[i] == max.first)
               max.second[i] = c[i];
            else {
               max.second.clear();
               max.second[i] = c[i];
            }
         }

         cout << cost << '\n';
      }
   }

   return 0;
}