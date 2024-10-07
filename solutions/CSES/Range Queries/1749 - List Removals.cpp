#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> a, seg;

void build(int v = 1, int l = 0, int r = n - 1) {
   if (l == r)
      seg[v] = 1;
   else {
      int m = (l + r) / 2;
      build(2 * v, l, m);
      build(2 * v + 1, m + 1, r);
      seg[v] = seg[2 * v] + seg[2 * v + 1];
   }
}

void update(int idx, int left = 0, int v = 1, int l = 0, int r = n - 1) {
   if (l == r) {
      cout << a[l] << " ";
      seg[v] = 0;
   } else {
      int m = (l + r) / 2;
      if (left + seg[2 * v] > idx)
         update(idx, left, 2 * v, l, m);
      else
         update(idx, left + seg[2 * v], 2 * v + 1, m + 1, r);
      seg[v] = seg[2 * v] + seg[2 * v + 1];
   }
}

void solve() {
   cin >> n;
   a.resize(n);
   seg.resize(4 * n);
   for (auto &i : a) cin >> i;
   build();
   for (int i = 0; i < n; i++) {
      int idx;
      cin >> idx;
      update(idx - 1);
   }
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);

   int t = 1;
   // cin >> t;
   while (t--) solve();
}