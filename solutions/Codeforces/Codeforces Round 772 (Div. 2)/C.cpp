#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<int, int> &a, pair<int, int> &b) {
   if (a.first == b.first) return a.second < b.second;
   return a.first < b.first;
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
      pair<int, int> b[n];
      for (int i = 0; i < n; i++) {
         cin >> a[i];
         b[i] = {a[i], i};
      }
      sort(b, b + n, cmp);

      if (a[n - 2] > a[n - 1]) {
         cout << "-1\n";
      } else {
         vector<int> vector;
         for (int i = 1; i < n - 2; ++i) {
         }
      }
   }

   return 0;
}