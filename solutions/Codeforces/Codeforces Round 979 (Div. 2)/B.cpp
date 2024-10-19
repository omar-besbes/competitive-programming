#include <bits/stdc++.h>
using namespace std;

void solve() {
   int n;
   cin >> n;
   string s;
   for (int i = 0; i < n - 1; i++) s += '0';
   s += '1';
   cout << s << "\n";
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);

   int t = 1;
   cin >> t;
   while (t--) solve();
}