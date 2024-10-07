#include <bits/stdc++.h>
using namespace std;

int main() {
   int n;
   cin >> n;
   long long a;
   cin >> a;
   long long cur = max(a, 0ll), maxi = a;
   for (int i = 1; i < n; i++) {
      cin >> a;
      cur += a;
      cur = max(cur, a);
      maxi = max(maxi, cur);
   }
   cout << maxi;
}