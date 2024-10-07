#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e6;

void solve() {
   int n;
   cin >> n;
   vector<int> a(maxN + 1);
   for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      a[x]++;
   }

   for (int _gcd = maxN; _gcd >= 1; _gcd--) {
      int nb = 0;
      for (int mul = _gcd; mul <= maxN; mul += _gcd) nb += a[mul];
      if (nb > 1) {
         cout << _gcd << "\n";
         break;
      }
   }
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);

   int t = 1;
   // cin >> t;
   while (t--) solve();
}