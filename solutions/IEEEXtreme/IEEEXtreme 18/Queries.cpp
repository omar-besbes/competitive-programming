#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, q;

struct SegTree {
   vector<ll> t;
   SegTree() { t.assign(4 * n, 0); }
   void update(int a, int b, int c, int v = 1, int l = 0, int r = n - 1) {
      if (a > r || b < l) return;
      if (a == l && b == r) {
         t[v] += c;
         return;
      }
      if (l < r) push(v);
      int m = (l + r) / 2;
      update(a, min(b, m), c, 2 * v, l, m);
      update(max(a, m + 1), b, c, 2 * v + 1, m + 1, r);
   }
   void push(int v) {
      t[2 * v] += t[v];
      t[2 * v + 1] += t[v];
      t[v] = 0;
   }
   ll query(int a, int b, int v = 1, int l = 0, int r = n - 1) {
      if (a > r || b < l) return 0;
      if (a == l && b == r) return t[v];
      if (l < r) push(v);
      int m = (l + r) / 2;
      auto ql = query(a, min(b, m), 2 * v, l, m);
      auto qr = query(max(a, m + 1), b, 2 * v + 1, m + 1, r);
      return ql + qr;
   }
};

int main() {
   cin >> n >> q;
   vector<int> p[2];
   p[0].resize(n), p[1].resize(n);
   for (int i = 0; i < n; i++) {
      cin >> p[0][i];
      p[0][i]--;
      p[1][p[0][i]] = i;
   }

   SegTree st[2];
   st[0] = SegTree(), st[1] = SegTree();
   for (int i = 0; i < q; i++) {
      int type, l, r, c;
      cin >> type;
      int mod = type % 2;
      if (type <= 1) {
         cin >> l >> r >> c;
         st[mod].update(l, r, c);
      } else {
         cin >> l >> r;
         ll ans = st[mod].query(l, r);
         cout << "\n\n";
         for (int i = l; i <= r; i++) {
            cout << p[1 - mod][i] << " ";
            ans += st[1 - mod].query(p[1 - mod][i], p[1 - mod][i]);
         }
         cout << ans << "\n";
      }
   }
}