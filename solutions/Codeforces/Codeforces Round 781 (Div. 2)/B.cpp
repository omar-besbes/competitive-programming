#include <bits/stdc++.h>

using namespace std;

bool compare(pair<const int, int> &a, pair<const int, int> &b) {
   return a.second < b.second;
}

int operation(int n, int p) {
   if (p <= n - p) return 1 + p;
   return 1 + n - p + operation(n, 2 * p - n);
}

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
      int a[n];
      map<int, int> map;
      for (auto &item : a) {
         cin >> item;
         map[item]++;
      }
      auto maxi = max_element(map.begin(), map.end(), compare);
      int p = n - maxi->second;
      int result = (n == 1 || p == 0) ? 0 : operation(n, p);
      cout << result << "\n";
   }

   return 0;
}