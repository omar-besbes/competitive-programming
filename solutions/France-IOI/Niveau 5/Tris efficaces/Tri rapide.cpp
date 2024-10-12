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

   auto partition = [&](int l, int r) {
      int pivot_val = a[r], pivot_idx = l;
      for (int j = l; j < r; j++)
         if (a[j] <= pivot_val) swap(a[pivot_idx], a[j]), pivot_idx++;
      swap(a[pivot_idx], a[r]);
      return pivot_idx;
   };

   queue<pair<int, int>> q;
   q.push(make_pair(0, n - 1));
   while (!q.empty()) {
      int l, r;
      tie(l, r) = q.front();
      q.pop();

      if (l >= r) continue;

      int pivot = partition(l, r);
      q.push(make_pair(l, pivot - 1));
      q.push(make_pair(pivot + 1, r));
   }

   for (auto &i : a) cout << i << " ";
}