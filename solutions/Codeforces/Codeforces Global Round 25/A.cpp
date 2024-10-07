#include "bits/stdc++.h"
using namespace std;

string solve() {
   int n;
   cin >> n;
   string s;
   cin >> s;

   int x = count(s.begin(), s.end(), '1');
   if (x == 2) {
      vector<int> a;
      for (int i = 0; i < n; i++)
         if (s[i] == '1') a.push_back(i);
      return (a[0] + 1 == a[1] ? "NO" : "YES");
   } else if (x & 1)
      return "NO";
   else
      return "YES";
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);

   int t;
   cin >> t;
   while (t--) cout << solve() << "\n";
}