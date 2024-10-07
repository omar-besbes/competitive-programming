#include "bits/stdc++.h"
using namespace std;

void solve() {
   string s, t;
   cin >> s >> t;
   int n = s.length(), m = t.length();
   int pos = 0;

   for (int i = 0; i < n; i++) {
      char expected = t[pos % m];
      if (s[i] == '?') {
         s[i] = expected;
         pos++;
      } else if (s[i] == expected) {
         pos++;
      }
   }

   if (pos < m)
      cout << "NO\n";
   else {
      cout << "YES\n";
      cout << s << "\n";
   }
}

int main() {
   int t;
   cin >> t;
   while (t--) solve();
}