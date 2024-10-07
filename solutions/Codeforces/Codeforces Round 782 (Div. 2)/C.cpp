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
      int n, a, b;
      cin >> n >> a >> b;
      n++;
      int x[n];
      x[0] = 0;
      for (int i = 1; i < n; ++i) {
         cin >> x[i];
      }
      long long sum = b * (x[1] - x[0]);
      int cu = 0;
      for (int i = 1; i < n - 1; ++i) {
         if ((n - i) * b * (x[i] - x[cu]) > a * (x[i] - x[cu])) {
            sum += a * (x[i] - x[cu]);
            cu = i;
            cout << "m";
         }
         cout << "c";
         sum += b * (x[i + 1] - x[cu]);
      }

      cout << sum << '\n';
   }

   return 0;
}