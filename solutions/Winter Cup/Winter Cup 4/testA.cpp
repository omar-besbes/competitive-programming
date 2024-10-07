#include <bits/stdc++.h>

using namespace std;

int main() {
   //    ios::sync_with_stdio(false);
   //    cin.tie(nullptr);
   //    cout.tie(nullptr);
   //    freopen("name.in", "r", stdin);
   //    freopen("input.txt", "r", stdin);
   //    freopen("output.txt", "w+", stdout);

   int n;
   cin >> n;
   long long ma = 0, ans = 0;
   for (int i = 1; i <= n; i++) {
      long long x;
      cin >> x;
      if (x > ma) {
         ma = x;
         ans = i;
      }
   }
   cout << ans << '\n';
   return 0;
}