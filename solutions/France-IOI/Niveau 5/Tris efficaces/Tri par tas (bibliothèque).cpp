#include "bits/stdc++.h"

using namespace std;

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);

   int n;
   cin >> n;
   vector<int> a(n);
   for (int i = 0; i < n; i++) {
      cin >> a[i];
   }

   make_heap(a.begin(), a.end());

   sort_heap(a.begin(), a.end());

   for (int i = 0; i < n; i++) {
      cout << a[i] << " ";
   }
}