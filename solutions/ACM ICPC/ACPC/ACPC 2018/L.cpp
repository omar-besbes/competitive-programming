#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int, int> &a, pair<int, int> &b) {
   return a.second > b.second;
}

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
      int n, k, answer = 0;
      cin >> n >> k;
      int a[n];
      for (int i = 0; i < n; ++i) {
         cin >> a[i];
      }
      for (int i = 0; i < 20; ++i) {
         bool b = false;
         for (int j = 0; (!b) && j < n; ++j) {
            if ((1 << i) & a[j]) b = true;
         }
         if (b) answer += (1 << i);
      }
      cout << answer << '\n';
   }

   return 0;
}