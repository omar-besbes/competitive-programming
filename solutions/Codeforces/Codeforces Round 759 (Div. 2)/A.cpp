#include <bits/stdc++.h>
using namespace std;

int main() {
   //    ios::sync_with_stdio(false);
   //    cin.tie(nullptr);
   //    cout.tie(nullptr);
   //    freopen("challenge.in", "r", stdin);
   //    freopen("input.txt", "r", stdin);
   //    freopen("output.txt", "w+", stdout);

   int t;
   cin >> t;
   while (t--) {
      int n, current, h = 1;
      bool watered;
      cin >> n >> current;
      if (current) {
         watered = true;
         h++;
      } else
         watered = false;
      for (int i = 1; i < n; ++i) {
         cin >> current;
         if (watered) {
            if (current)
               h += 5;
            else
               watered = false;
         } else {
            if (current) {
               watered = true;
               h++;
            } else {
               h = -1;
               while (++i < n) cin >> current;
               break;
            }
         }
      }

      cout << h << '\n';
   }

   return 0;
}