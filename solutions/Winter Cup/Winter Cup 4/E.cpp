#include <bits/stdc++.h>

using namespace std;

int main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);
   //    freopen("name.in", "r", stdin);
   //   freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w+", stdout);
   int t;
   cin >> t;
   while (t--) {
      int n;
      cin >> n;
      int a[n][n];
      int c[n], r[n], nbc = 0, nbr = 0, s1 = 0, s2 = 0;
      for (int i = 0; i < n; ++i) {
         cin >> c[i];
         if (c[i]) nbc++;
         s1 += c[i];
      }
      for (int i = 0; i < n; ++i) {
         cin >> r[i];
         if (r[i]) nbr++;
         s2 += r[i];
      }
      bool ok = 1;
      pair<int, int> b[n];
      for (int i = 0; i < n; ++i) {
         b[i] = make_pair(c[i], i);
      }
      sort(b, b + n);
      reverse(b, b + n);
      for (int i = 0; i < n; ++i) {
         for (int j = 0; j < n; ++j) {
            a[i][j] = 0;
         }
      }
      for (int i = 0; i < n; i++) {
         for (int j = 0; j < r[i]; ++j) {
            if (b[j].first == 0) ok = 0;
            a[i][b[j].second] = 1;
            b[j].first--;
         }
         sort(b, b + n);
         reverse(b, b + n);
         // cout << '\n';
      }
      if (b[0].first > 0) ok = 0;
      if (!ok) {
         cout << "-1\n";
         continue;
      }
      for (int i = 0; i < n; ++i) {
         for (int j = 0; j < n; ++j) {
            cout << a[i][j] << ' ';
         }
         cout << '\n';
      }
   }

   return 0;
}