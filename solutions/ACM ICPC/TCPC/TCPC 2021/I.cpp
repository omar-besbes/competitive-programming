#include <bits/stdc++.h>
using namespace std;

int main() {
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   freopen("cipher.in", "r", stdin);
   // freopen("input.txt.txt", "r", stdin);
   int t = 1;
   // cin >> t;
   while (t--) {
      string a, b;
      getline(cin, b);
      getline(cin, a);
      // cout << a << '\n';
      // cout << b << '\n';
      string k = "";
      for (int i = 0; i < a.length(); i++) {
         if (isalpha(a[i])) {
            int cu = ((int)(b[i]) + 26 - (int)(a[i]));
            cu %= 26;
            if (cu < 0) cu += 26;
            k += (char)('a' + cu);
         }
      }
      // cout << k << '\n';
      for (int i = 1; i <= k.length(); i++) {
         string s = "";
         for (int j = 0; j < k.length(); j++) s += k[j % i];
         // cout << s << '\n';
         if (s == k) {
            s = "";
            for (int j = 0; j < i; j++) s += k[j];
            cout << s << '\n';
            return 0;
         }
      }
   }
}
