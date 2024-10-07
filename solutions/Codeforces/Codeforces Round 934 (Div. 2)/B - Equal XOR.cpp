#include "bits/stdc++.h"
using namespace std;

#define N (int)5e4

int a[2 * N];

void solve() {
   int n, k;
   cin >> n >> k;
   map<int, int> occ[2];
   for (int i = 0; i < 2 * n; i++) {
      cin >> a[i];
      occ[i / n][a[i]]++;
   }

   sort(a, a + n, [&occ](auto &l, auto &r) {
      if (occ[0][l] == occ[0][r]) return l < r;
      return occ[0][l] > occ[0][r];
   });
   sort(a + n, a + 2 * n, [&occ](auto &l, auto &r) {
      if (occ[1][l] == occ[1][r]) return l < r;
      return occ[1][l] > occ[1][r];
   });

   vector<int> left, right;
   for (int i = 0; i < 2 * k; i++)
      left.push_back(a[i]), right.push_back(a[i + n]);

   for (auto &i : left) cout << i << " ";
   cout << "\n";
   for (auto &i : right) cout << i << " ";
   cout << "\n";
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);

   int t;
   cin >> t;
   while (t--) {
      solve();
   }
}