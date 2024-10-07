#include "bits/stdc++.h"
using namespace std;

void solve() {
   int n, k;
   cin >> n >> k;
   for (int i = 0; i < n; i++) {
      string s;
      cin >> s;
      if (i % k == 0) {
         for (int j = 0; j < n; j += k) cout << s[j] - '0';
         cout << "\n";
      }
   }
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);

   int t;
   cin >> t;
   while (t--) solve();
}