#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int mod = 1e9 + 7;
const int k = 3;

vector<vector<ll>> p{{1, 31}, {1, 37}, {1, 41}};

void compute_powers(int n) {
   for (int j = 0; j < k; j++) {
      p[j].resize(n + 1);
      for (int i = 2; i < n; i++) p[j][i] = p[j][i - 1] * p[j][1] % mod;
   }
}

vector<ll> hash1(string x, vector<ll> &p) {
   int n = x.length();
   vector<ll> h(n + 1);
   for (int i = 0; i < n; i++)
      h[i + 1] = (h[i] + (x[i] - 'a' + 1) * p[i]) % mod;
   return h;
}

ll hash2(string x, vector<ll> &p) {
   int n = x.length();
   ll h = 0;
   for (int i = 0; i < n; i++) h = (h + (x[i] - 'a' + 1) * p[i]) % mod;
   return h;
}

int res(string s, string t) {
   int n = s.length(), m = t.length();

   if (m > n) return 0;

   compute_powers(n);

   vector<ll> ht(k, 0);
   vector<vector<ll>> hs(k, vector<ll>(n + 1));
   for (int i = 0; i < k; i++) ht[i] = hash2(t, p[i]), hs[i] = hash1(s, p[i]);

   int ans = 0;
   for (int i = 0; i + m - 1 < n; i++) {
      bool yes = true;
      for (int j = 0; j < k; j++) {
         ll cur = (hs[j][i + m] + mod - hs[j][i]) % mod;
         if (cur != ht[j] * p[j][i] % mod) yes = false;
      }
      if (yes) ans++;
   }

   return ans;
}

void solve() {
   string s, t;
   cin >> s >> t;
   cout << res(s, t) << "\n";
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);

   int t = 1;
   // cin >> t;
   while (t--) solve();
}