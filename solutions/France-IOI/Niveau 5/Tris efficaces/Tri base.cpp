#include <bits/stdc++.h>
using namespace std;

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);

   int n;
   cin >> n;
   vector<int> a(n);
   for (auto &i : a) cin >> i;

   queue<tuple<int, int, int>> q;
   q.push(make_tuple(0, n - 1, 31));
   while (!q.empty()) {
      int l, r, b;
      tie(l, r, b) = q.front();

      if (l >= r || b < 0) {
         q.pop();
         continue;
      }

      while (l < r) {
         if (a[l] & (1 << b))
            swap(a[l], a[r]), r--;
         else
            l++;
      }

      int m = (a[l] & (1 << b)) ? l - 1 : l;
      tie(l, r, b) = q.front();
      q.push(make_tuple(l, m, b - 1));
      q.push(make_tuple(m + 1, r, b - 1));
      q.pop();
   }

   for (auto i : a) cout << i << " ";
}