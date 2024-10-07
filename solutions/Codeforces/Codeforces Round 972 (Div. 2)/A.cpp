#include <bits/stdc++.h>
using namespace std;

void solve() {
   int n;
   cin >> n;
   vector<char> v{'a', 'e', 'i', 'o', 'u'};
   int base = n / 5, r = n % 5;
   for (int i = 0; i < 5; i++) {
      for (int j = 0; j < base + (i < r ? 1 : 0); j++) cout << v[i];
   }
   cout << "\n";
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);

   int t = 1;
   cin >> t;
   while (t--) solve();
}