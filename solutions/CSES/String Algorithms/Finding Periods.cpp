#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll mod = 1e9 + 7;

void solve() {
   string s;
   cin >> s;
   int n = s.length();

   vector<ll> p{1, 31};
   for (int i = 2; i < n; i++) p.push_back(p[1] * p[i - 1] % mod);

   vector<ll> h(n + 1);
   for (int i = 0; i < n; i++)
      h[i + 1] = (h[i] + (s[i] - 'a' + 1) * p[i]) % mod;

   for (int i = 1; i <= n; i++) {
      bool yes = true;
      for (int j = i; yes && j < n; j += i) {
         int l = min(i, n - j);
         if (h[l] * p[j] % mod != (h[j + l] - h[j] + mod) % mod) yes = false;
      }
      if (yes) cout << i << " ";
   }
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);

   int t = 1;
   // cin >> t;
   while (t--) solve();
}