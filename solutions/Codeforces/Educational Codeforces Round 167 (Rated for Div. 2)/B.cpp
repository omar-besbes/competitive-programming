#include "bits/stdc++.h"
using namespace std;

void solve() {
   string a, b;
   cin >> a >> b;
   int res = a.length() + b.length();
   for (int i = 0; i < b.length(); i++) {
      int tmp = a.length() + b.length();
      int k = i;
      for (int j = 0; j < a.length() && k < b.length(); j++) {
         if (a[j] == b[k]) k++, tmp--;
      }
      res = min(res, tmp);
   }

   cout << res << "\n";
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);

   int t;
   cin >> t;
   while (t--) solve();
}