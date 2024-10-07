#include "bits/stdc++.h"

using namespace std;

#define N (int)1e5

int n;
map<int, int> p[N];
int m[N];

int c_w(int a, int b) {
   // already computed
   if (p[a][b]) return p[a][b];
   // compute if not already computed
   int res = 1;
   for (auto &c : p[b]) {
      if (c.first != a) res += c_w(b, c.first);
   }
   p[a][b] = res;
   m[a] = max(res, m[a]);
   return p[a][b];
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);

   cin >> n;
   for (int i = 0; i < n - 1; i++) {
      int a, b;
      cin >> a >> b;
      p[a][b] = 0;
      p[b][a] = 0;
   }

   // compute edges weights 2*(n-1)
   for (int i = 0; i < n; i++)
      for (auto &d : p[i])
         // root cannot be leaf
         if (p[i].size() > 1) c_w(i, d.first);

   int res = INT_MAX;
   for (int i = 0; i < N; i++)
      if (m[i]) res = min(res, m[i]);

   cout << res << "\n";
}