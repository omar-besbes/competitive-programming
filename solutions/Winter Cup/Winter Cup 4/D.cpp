#include <bits/stdc++.h>

using namespace std;

int main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);
   //    freopen("name.in", "r", stdin);
   //   freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w+", stdout);
   int t;
   cin >> t;
   while (t--) {
      int n;
      cin >> n;
      string s;
      cin >> s;
      int a[11];
      for (int i = 0; i < 11; ++i) {
         a[i] = 0;
      }
      a[0] = 1;
      int s1 = 0;
      long long ans = 0;
      for (int i = 0; i < s.length(); ++i) {
         if (i % 2)
            s1 += (s[i] - '0');
         else
            s1 -= (s[i] - '0');
         int cu = s1;
         cu %= 11;
         cu += 11;
         cu %= 11;
         ans += a[cu];
         a[cu]++;
      }
      cout << ans << '\n';
   }

   return 0;
}