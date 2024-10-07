#include <bits/stdc++.h>

using namespace std;

int m(const int *a, int n) {
   int max = a[0];
   for (int i = 1; i < n; ++i) {
      if (a[i] > max) max = a[i];
   }
   return max;
}

int mexa(int *a, int n, vector<int> &b) {
   int maxi = m(a, n), mex = 0, i;
   set<int> c;
   for (i = 0; i < n && mex <= maxi; ++i) {
      c.insert(a[i]);
      while (c.find(mex) != c.end()) {
         mex++;
      }
   }
   b.push_back(mex);
   return i;
}

int main() {
   //    ios::sync_with_stdio(false);
   //    cin.tie(nullptr);
   //    cout.tie(nullptr);
   //    freopen("name.in", "r", stdin);
   //    freopen("input.txt", "r", stdin);
   //    freopen("output.txt", "w+", stdout);

   int t;
   cin >> t;
   while (t--) {
      int n;
      cin >> n;
      int a[n], index = 0;
      vector<int> b;
      for (int i = 0; i < n; ++i) {
         cin >> a[i];
      }
      while (index < n) {
         index += mexa(a + index, n - index, b);
      }
      cout << b.size() << '\n';
      for (auto i : b) {
         cout << i << ' ';
      }
      cout << '\n';
   }

   return 0;
}