#include <bits/stdc++.h>

using namespace std;

int main() {
   //    ios::sync_with_stdio(false);
   //    cin.tie(nullptr);
   //    cout.tie(nullptr);
   //    freopen("name.in", "r", stdin);
   //    freopen("input.txt", "r", stdin);
   //    freopen("output.txt", "w+", stdout);

   int t;
   cin >> t;
   while (t--) {
      long long n, m, cu;
      cin >> n >> m;
      if (m < n) swap(n, m);
      long long x;
      cu = 2 * n + m - 2;
      // cout << cu << ' ';
      x = cu + 1;
      x *= cu;
      x /= (2LL);
      cu = m;
      cu *= (m + 1LL);
      cu /= 2LL;
      x += cu;
      cout << x << '\n';
   }

   return 0;
}