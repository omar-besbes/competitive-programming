#include <bits/stdc++.h>
using namespace std;

void solve() {
   long long k;
   cin >> k;
   k--;
   long long cur = 9, d = 1;
   while (k >= d * cur) k -= d * cur, d++, cur *= 10;
   long long pref = cur / 9, offset = k / d;
   long long nb = offset + pref;
   long long pos = d - (k % d) - 1;
   while (pos) nb /= 10, pos--;
   cout << nb % 10 << "\n";
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);

   int t = 1;
   cin >> t;
   while (t--) solve();
}