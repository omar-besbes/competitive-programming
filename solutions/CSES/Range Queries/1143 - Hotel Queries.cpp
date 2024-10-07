#include <bits/stdc++.h>

using namespace std;

int n, q;
vector<int> a, t;

void build(int v = 1, int tl = 0, int tr = n - 1) {
   if (tl == tr)
      t[v] = a[tl];
   else {
      int tm = (tl + tr) / 2;
      build(2 * v, tl, tm);
      build(2 * v + 1, tm + 1, tr);
      t[v] = max(t[2 * v], t[2 * v + 1]);
   }
}

void update(int idx, int nb, int v = 1, int tl = 0, int tr = n - 1) {
   if (idx < tl || idx > tr)
      return;
   else if (tl == tr)
      t[v] = nb, a[idx] = nb;
   else {
      int tm = (tl + tr) / 2;
      update(idx, nb, 2 * v, tl, tm);
      update(idx, nb, 2 * v + 1, tm + 1, tr);
      t[v] = max(t[2 * v], t[2 * v + 1]);
   }
}

int query(int nb, int v = 1, int tl = 0, int tr = n - 1) {
   if (tl == tr) {
      return nb <= t[v] ? tl + 1 : 0;
   } else {
      int tm = (tl + tr) / 2;
      if (nb > t[2 * v])
         return query(nb, 2 * v + 1, tm + 1, tr);
      else
         return query(nb, 2 * v, tl, tm);
   }
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);

   cin >> n >> q;
   a.resize(n);
   t.resize(4 * n);

   for (int i = 0; i < n; ++i) cin >> a[i];

   build();

   for (int i = 0; i < q; i++) {
      int nb;
      cin >> nb;
      auto idx = query(nb);
      if (idx != 0) update(idx - 1, a[idx - 1] - nb);
      cout << idx << " ";
   }
}
