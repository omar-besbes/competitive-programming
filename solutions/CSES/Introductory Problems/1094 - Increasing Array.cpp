#include <bits/stdc++.h>
using namespace std;

int main() {
   int n;
   cin >> n;
   int last, curr;
   cin >> curr;
   long long ans = 0;
   for (int i = 1; i < n; i++) {
      last = curr;
      cin >> curr;
      ans += max(0, last - curr);
      curr = max(curr, last);
   }
   cout << ans;
}