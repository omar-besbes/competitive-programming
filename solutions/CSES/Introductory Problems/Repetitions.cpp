#include <bits/stdc++.h>
using namespace std;

int main() {
   string s;
   cin >> s;
   int ans = 1;
   for (int i = 0; i < s.length(); i++) {
      int sum = 1;
      while (i + 1 < s.length() && s[i] == s[i + 1]) sum++, i++;
      ans = max(ans, sum);
   }
   cout << ans;
}