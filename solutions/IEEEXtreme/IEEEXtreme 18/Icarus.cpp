#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
   string s;
   cin >> s;
   ll count = 0, maxi = 0, mini = 0;
   ll n = s.size();
   ll b, a = 0;
   for (int i = 0; i < n; i++) {
      if (s[i] == 'U')
         count++;
      else if (s[i] == 'L')
         count--;
      maxi = max(maxi, count);
      mini = min(mini, count);
   }
   if (count > 0) {
      b = mini - 1;
      mini--;
   } else {
      b = maxi + 1;
      maxi++;
   }
   if (b == maxi)
      b = 1;
   else
      b = maxi - mini + 1;
   cout << maxi - mini + 1 << " " << maxi + 1 << " " << b << endl;
   for (int i = 1; i < maxi - mini + 1; i++) {
      cout << i + 1 << " " << 0 << endl;
   }
   cout << "0 0" << endl;
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);

   int t = 1;
   // cin >> t;
   while (t--) {
      solve();
   }
}
