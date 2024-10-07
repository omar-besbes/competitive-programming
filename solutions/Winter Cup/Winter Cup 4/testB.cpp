#include <bits/stdc++.h>

using namespace std;

int main() {
   //    ios::sync_with_stdio(false);
   //    cin.tie(nullptr);
   //    cout.tie(nullptr);
   //    freopen("name.in", "r", stdin);
   //    freopen("input.txt", "r", stdin);
   //    freopen("output.txt", "w+", stdout);

   int n, L, sum = 0;
   cin >> n >> L;
   int a[n];
   for (auto &item : a) {
      cin >> item;
      sum += item;
   }
   if (sum > L)
      cout << "NO\n";
   else
      cout << "YES\n";

   return 0;
}