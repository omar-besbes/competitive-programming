#include <bits/stdc++.h>
using namespace std;

void solve() {
   int n;
   cin >> n;
   string s;
   cin >> s;
   bool yes = s[0] == '1' || s[n - 1] == '1';
   for (int i = 1; !yes && i < n; i++)
      if (s[i] == s[i - 1] && s[i] == '1') yes = true;
   cout << (yes ? "YES" : "NO") << "\n";
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);

   int t = 1;
   cin >> t;
   while (t--) solve();
}