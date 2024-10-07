#include "bits/stdc++.h"

using namespace std;

int n, r;
vector<int> seg;

void init(int index = 1, int l = 0, int r = n - 1) {
   if (l == r) {
      seg[index] = 0;
   } else {
      int m = (l + r) / 2;
      seg[index] = -1;
      init(2 * index, l, m);
      init(2 * index + 1, m + 1, r);
   }
}

int update(int key, int value, int index = 1, int l = 0, int r = n - 1) {
   if (key < l || key > r)
      return l == r ? (seg[index] == 1 ? l : -1) : seg[index];
   if (l == r) {
      seg[index] = value;
      return value == 1 ? key : -1;
   } else {
      int m = (l + r) / 2;
      int left = update(key, value, 2 * index, l, m);
      int right = update(key, value, 2 * index + 1, m + 1, r);
      return seg[index] = right == -1 ? left : right;
   }
}

int get(int index, int v = 1, int l = 0, int r = n - 1) {
   if (l > index) return -1;
   if (l == r) {
      return seg[v] == 1 ? l : -1;
   } else if (r <= index) {
      return seg[v];
   } else {
      int m = (l + r) / 2;
      int left = get(index, 2 * v, l, m);
      int right = get(index, 2 * v + 1, m + 1, r);
      return right == -1 ? left : right;
   }
}

void print() {
   for (int i = 1; i < 4 * n; i++) cout << seg[i] << " ";
   cout << "\n";
}

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);

   cin >> n;
   seg.resize(4 * n);

   init();

   cin >> r;
   for (int i = 0; i < r; i++) {
      char type;
      cin >> type;
      if (type == 'M') {
         int key, value;
         cin >> key >> value;
         update(key, value);
      } else {
         int index;
         cin >> index;
         cout << get(index) << "\n";
      }
   }
}