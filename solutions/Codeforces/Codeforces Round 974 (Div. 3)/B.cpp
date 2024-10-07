#include <bits/stdc++.h>
using namespace std;

void solve() {
   int n, k;
   cin >> n >> k;

   int odd = k / 2 + (((n - k + 1) & 1) && (k & 1) ? 1 : 0);

   cout << (odd & 1 ? "NO\n" : "YES\n");
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);

   int t = 1;
   cin >> t;
   while (t--) solve();
}