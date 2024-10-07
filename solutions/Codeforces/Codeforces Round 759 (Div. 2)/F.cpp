#include <bits/stdc++.h>
#define MOD 998244353;
using namespace std;

int main() {
   //    ios::sync_with_stdio(false);
   //    cin.tie(nullptr);
   //    cout.tie(nullptr);
   //    freopen("challenge.in", "r", stdin);
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w+", stdout);

   int n, result = 1;
   cin >> n;
   int a[n], b[n];
   for (int i = 0; i < n; ++i) {
      cin >> a[i];
      result *= a[i];
      result %= MOD;
      b[i] = result;
   }

   int remove = 0;
   for (int i = 1; i < n; ++i) {
      int r = b[n - 1] / b[i], mini = min(a[i - 1], a[i]);
      r *= mini;
      for (int j = 0; j < i - 1; ++j) {
         int x = min(a[j], a[j + 1]);
         r *= x;
         r %= MOD;
      }
      remove += r;
   }
   result -= remove;
   cout << result;
   return 0;
}