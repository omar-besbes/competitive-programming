#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll

void solve() {
   int z, o;
   cin >> z >> o;
   if (o & 1) {
      cout << "Second" << endl;
   } else
      cout << "First" << endl;
}

signed main() {
   ios::sync_with_stdio(false);
   cin.tie(0);

   int tt = 1;
   cin >> tt;
   while (tt--) {
      solve();
   }
}