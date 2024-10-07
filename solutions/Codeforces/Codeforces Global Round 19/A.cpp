#include <bits/stdc++.h>

using namespace std;

int main() {
   //    ios::sync_with_stdio(false);
   //    cin.tie(nullptr);
   //    cout.tie(nullptr);
   //    freopen("name.in", "r", stdin);
   //    freopen("input.txt", "r", stdin);
   //    freopen("output.txt", "w+", stdout);

   int t;
   cin >> t;
   while (t--) {
      int n;
      cin >> n;
      int a[n], b[n];
      for (int i = 0; i < n; ++i) {
         cin >> a[i];
         b[i] = a[i];
      }
      sort(a, a + n);
      int i = 0;
      while (i < n && a[i] == b[i]) i++;
      if (i == n)
         cout << "NO\n";
      else
         cout << "YES\n";
   }

   return 0;
}