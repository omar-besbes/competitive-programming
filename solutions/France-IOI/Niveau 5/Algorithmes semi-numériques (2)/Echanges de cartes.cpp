#include "bits/stdc++.h"
using namespace std;

int main() {
   int n;
   cin >> n;
   vector<int> a(n);
   for (auto &i : a) cin >> i;

   vector<pair<int, int>> ops;
   for (int i = 0; i < n; i++) {
      while (a[i] != i + 1) {
         ops.emplace_back(i + 1, a[i]);
         swap(a[i], a[a[i] - 1]);
      }
   }
   cout << ops.size() << "\n";
   for (auto &i : ops) cout << i.first << " " << i.second << "\n";
}