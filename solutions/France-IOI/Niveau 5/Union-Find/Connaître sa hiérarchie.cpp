#include "bits/stdc++.h"

using namespace std;

int n, r;
vector<int> parent, enterprise;

int find_set(int v) {
   if (v == enterprise[v]) {
      return v;
   } else {
      return enterprise[v] = find_set(enterprise[v]);
   }
}

bool join_set(int x, int y) {
   x = find_set(x);
   y = find_set(y);

   if (x != y) {
      enterprise[y] = enterprise[x];
      parent[y] = parent[x];
   }

   return x != y;
}

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);

   cin >> n >> r;
   parent.assign(n, 0);
   enterprise.assign(n, 0);
   for (int i = 0; i < n; ++i) {
      parent[i] = i;
      enterprise[i] = i;
   }

   for (int i = 0; i < r; ++i) {
      int x, y;
      cin >> x >> y;
      if (x == y) {
         do {
            x = y;
            y = parent[x];
            cout << x << " ";
         } while (x != y);
         cout << "\n";
      } else {
         join_set(x, y);
      }
   }
}