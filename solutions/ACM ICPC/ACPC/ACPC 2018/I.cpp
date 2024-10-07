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
      int n, k;
      cin >> n >> k;
      pair<int, int> iceCream[n];
      for (int i = 0; i < n; ++i) {
         cin >> iceCream[i].first;
      }
      for (int i = 0; i < n; ++i) {
         cin >> iceCream[i].second;
      }
      sort(iceCream, iceCream + n);
      cout << iceCream[k - 1].first << ' ';
      int batch = k;
      while (batch < n && iceCream[batch].first == iceCream[batch - 1].first)
         batch++;
      sort(iceCream, iceCream + batch, compare);
      long long happiness = 0;
      while (k--) happiness += iceCream[k].second;
      cout << happiness << '\n';
   }

   return 0;
}