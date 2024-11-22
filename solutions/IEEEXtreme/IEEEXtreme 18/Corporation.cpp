#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

pair<ll, int> operator+(const pair<ll, int> &a, const pair<ll, int> &b) {
   return {a.first + b.first, a.second + b.second};
}

int n, q;

struct SegTree {
   vector<ll> t, maxT, minT, lazyAdd, lazyReplace;
   vector<bool> marked;
   vector<int> happ, lazyHapp;
   SegTree(vector<int> &a) {
      marked.assign(4 * n, false);
      lazyAdd.assign(4 * n, 0);
      lazyReplace.assign(4 * n, 0);
      happ.assign(4 * n, 0);
      lazyHapp.assign(4 * n, 0);
      t.resize(4 * n);
      maxT.resize(4 * n);
      minT.resize(4 * n);
      build(a);
   }
   void build(vector<int> &a, int v = 1, int l = 0, int r = n - 1) {
      if (l == r) {
         t[v] = a[l];
         maxT[v] = t[v];
         minT[v] = t[v];
      } else {
         int m = (l + r) / 2;
         build(a, 2 * v, l, m);
         build(a, 2 * v + 1, m + 1, r);
         t[v] = t[2 * v] + t[2 * v + 1];
         maxT[v] = max(maxT[2 * v], maxT[2 * v + 1]);
         minT[v] = max(minT[2 * v], minT[2 * v + 1]);
      }
   }
   void compose(int p, int c) {
      if (marked[p]) {
         lazyAdd[c] = lazyAdd[p];
         lazyReplace[c] = lazyAdd[p];
         marked[c] = true;
      } else {
         lazyAdd[c] += lazyAdd[p];
      }

      lazyHapp[c] += lazyHapp[p];
   }
   void push(int v, int l, int r) {
      int m = (l + r) / 2;
      if (marked[v]) {
         t[v] = (r - l + 1) * lazyReplace[v];
         maxT[v] = minT[v] = lazyReplace[v];
      }

      t[v] += (r - l + 1) * lazyAdd[v];
      maxT[v] = max(maxT[v], maxT[v] + lazyAdd[v]);
      minT[v] = max(minT[v], minT[v] + lazyAdd[v]);
      happ[v] += (r - l + 1) * lazyHapp[v];

      if (l != r) {
         compose(v, 2 * v);
         compose(v, 2 * v + 1);
      }

      marked[v] = false;
      lazyAdd[v] = 0;
      lazyHapp[v] = 0;
   }
   void add(int a, int b, int c, int v = 1, int l = 0, int r = n - 1) {
      if (a > b || a > r || b < l) return;
      if (a == l && b == r) {
         lazyAdd[v] += c;
         if (c > 0)
            lazyHapp[v]++;
         else
            lazyHapp[v]--;
         return;
      }
      push(v, l, r);
      int m = (l + r) / 2;
      add(a, min(b, m), c, 2 * v, l, m);
      add(max(a, m + 1), b, c, 2 * v + 1, m + 1, r);
      push(2 * v, l, m);
      push(2 * v + 1, m + 1, r);
      t[v] = t[2 * v] + t[2 * v + 1];
      maxT[v] = max(maxT[2 * v], maxT[2 * v + 1]);
      minT[v] = max(minT[2 * v], minT[2 * v + 1]);
      happ[v] = happ[2 * v] + happ[2 * v + 1];
   }
   void replace(int a, int b, int c, int v = 1, int l = 0, int r = n - 1) {
      if (a > b || a > r || b < l) return;
      if (a == l && b == r &&
          (c > maxT[v] + lazyAdd[v] || c < minT[v] + lazyAdd[v] || l == r)) {
         if (c > maxT[v] + lazyAdd[v])
            lazyHapp[v]++;
         else if (c < minT[v] + lazyAdd[v])
            lazyHapp[v]--;
         else
            lazyHapp[v] += c > t[v] + lazyAdd[v] ? 1 : -1;
         lazyReplace[v] = c;
         lazyAdd[v] = 0;
         marked[v] = true;
         return;
      }
      push(v, l, r);
      int m = (l + r) / 2;
      replace(a, min(b, m), c, 2 * v, l, m);
      replace(max(a, m + 1), b, c, 2 * v + 1, m + 1, r);
      push(2 * v, l, m);
      push(2 * v + 1, m + 1, r);
      t[v] = t[2 * v] + t[2 * v + 1];
      maxT[v] = max(maxT[2 * v], maxT[2 * v + 1]);
      minT[v] = max(minT[2 * v], minT[2 * v + 1]);
      happ[v] = happ[2 * v] + happ[2 * v + 1];
   }
   pair<ll, int> query(int a, int b, int v = 1, int l = 0, int r = n - 1) {
      if (a > b || a > r || b < l) return make_pair(0LL, 0);
      push(v, l, r);
      if (a == l && b == r) return make_pair(t[v], happ[v]);
      int m = (l + r) / 2;
      auto ql = query(a, min(b, m), 2 * v, l, m);
      auto qr = query(max(a, m + 1), b, 2 * v + 1, m + 1, r);
      return ql + qr;
   }
   void print() {
      queue<tuple<int, int, int>> q, tmp;
      q.push({1, 0, n - 1});
      while (!q.empty()) {
         while (!q.empty()) {
            auto [v, l, r] = q.front();
            cout << "(" << t[v] << "," << lazyAdd[v] << "," << lazyReplace[v]
                 << "," << happ[v] << "," << lazyHapp[v] << ") ";
            q.pop();

            if (l < r) {
               int m = (l + r) / 2;
               tmp.push({2 * v, l, m});
               tmp.push({2 * v + 1, m + 1, r});
            }
         }
         cout << "\n";
         q.swap(tmp);
      }
      cout << "\n\n";
   }
};

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);

   cin >> n >> q;
   vector<int> a(n);
   for (auto &i : a) cin >> i;
   SegTree st(a);

   while (q--) {
      int type, l, r, c;
      cin >> type;
      if (type <= 1) {
         cin >> l >> r >> c;
         l--, r--;
         if (type == 0)
            st.replace(l, r, c);
         else
            st.add(l, r, c);
      } else {
         cin >> l >> r;
         l--, r--;
         auto [sal, hap] = st.query(l, r);
         ll ans = type == 2 ? sal : hap;
         ll len = r - l + 1;
         auto g = gcd(abs(ans), len);
         cout << ans / g << "/" << len / g << "\n";
      }
      // st.print();
   }
}
