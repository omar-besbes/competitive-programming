#include "bits/stdc++.h"

using namespace std;

#define NOT_MARKED -1

int h, n, r;
vector<int> seg;

void init(int v = 1, int l = 0, int r = n - 1) {
   if (l == r) {
      seg[v] = 0;
   } else {
      int m = (l + r) / 2;
      seg[v] = NOT_MARKED;
      init(2 * v, l, m);
      init(2 * v + 1, m + 1, r);
   }
}

void update(pair<int, int> range, int value, int v = 1, int l = 0,
            int r = n - 1) {
   if (range.first > range.second) return;
   if (range.first == l && r == range.second) {
      seg[v] = value;
   } else {
      int m = (l + r) / 2;

      if (seg[v] != NOT_MARKED)
         seg[2 * v] = seg[v], seg[2 * v + 1] = seg[v], seg[v] = NOT_MARKED;

      update(make_pair(range.first, min(m, range.second)), value, 2 * v, l, m);
      update(make_pair(max(m + 1, range.first), range.second), value, 2 * v + 1,
             m + 1, r);
   }
}

int get(int index, int v = 1, int l = 0, int r = n - 1) {
   if (index < l || index > r) return NOT_MARKED;
   if (l == r || seg[v] != NOT_MARKED)
      return seg[v];
   else {
      int m = (l + r) / 2;
      int left = get(index, 2 * v, l, m);
      int right = get(index, 2 * v + 1, m + 1, r);
      return index > m ? right : left;
   }
}

void print() {
   for (int i = 1; i < 2 * n; i++) cout << seg[i] << " ";
   cout << "\n";
}

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);

   cin >> h;
   n = 1 << h;
   seg.resize(2 * n);
   seg.assign(2 * n, 0);

   init();

   cin >> r;
   for (int i = 0; i < r; i++) {
      char type;
      cin >> type;
      if (type == 'M') {
         int l, r, value;
         cin >> l >> r >> value;
         update(make_pair(l, r), value);
      } else {
         int index;
         cin >> index;
         cout << get(index) << "\n";
      }
   }
}