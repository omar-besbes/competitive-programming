#include <bits/stdc++.h>
using namespace std;
#define input "input.in"
#define output "output.out"
#define ll long long
#define int ll

const int MAXI = 1 << 20;

void solve() {
   int n;
   cin >> n;
   vector<int> v(n);
   int mini = 0;
   for (auto& i : v) {
      cin >> i;
      mini += i;
   }

   int m = (1 << n) - 1;
   for (int s = m; s; s = (s - 1) & m) {
      int a = 0, b = 0;
      for (int i = 0; i < n; i++) {
         if ((1 << i) & s) {
            // cout << "0 ";
            a += v[i];
         } else {
            // cout << "1 ";
            b += v[i];
         }
      }
      // cout << "\n";
      // cout << "a = " << a << " b = " << b << "\n";

      mini = min(mini, abs(a - b));
   }

   cout << mini;
}

int32_t main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);

   if (fopen(input, "r")) freopen(input, "r", stdin);
   if (fopen(output, "r")) freopen(output, "w+", stdout);

   int t = 1;
   // cin >> t;
   while (t--) solve();
}
