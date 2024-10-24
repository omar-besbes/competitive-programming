#include <bits/stdc++.h>
using namespace std;

void solve() {
   int n;
   cin >> n;
   cout << (n % 2 ? "Kosuke" : "Sakurako") << "\n";
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);

   int t = 1;
   cin >> t;
   while (t--) solve();
}