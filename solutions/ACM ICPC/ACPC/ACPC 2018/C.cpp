#include <bits/stdc++.h>
using namespace std;

int main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);
   //    freopen("challenge.in", "r", stdin);
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w+", stdout);

   int t;
   cin >> t;
   while (t--) {
      int C, P;
      cin >> C >> P;
      int fees;
      map<string, vector<int>> coffee;

      for (int i = 0; i < C; ++i) {
         int x, y, z;
         string string1;
         cin >> string1 >> x >> y >> z;
         coffee[string1].push_back(x);
         coffee[string1].push_back(y);
         coffee[string1].push_back(z);
      }

      for (int i = 0; i < P; ++i) {
         string string1, string2, string3;
         cin >> string1 >> string2 >> string3;

         fees = 100 / P;
         if (string2 == "small")
            fees += coffee[string3][0];
         else if (string2 == "medium")
            fees += coffee[string3][1];
         else
            fees += coffee[string3][2];
         if (fees % 5 == 1) fees--;
         if (fees % 5 == 4) fees++;

         cout << string1 << ' ' << fees << '\n';
      }
   }

   return 0;
}