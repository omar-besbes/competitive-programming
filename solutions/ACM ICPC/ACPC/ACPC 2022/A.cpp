#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll

const int N = 3e6 + 100;
const int mod = 1e9 + 7;

int binpow(int a, int b) {
   int res = 1;
   while (b) {
      if (b & 1) {
         res *= a;
         res %= mod;
      }
      b /= 2;
      a *= a;
      a %= mod;
   }
   return res;
}
int inv(int n) { return binpow(n, mod - 2) % mod; }
int fact[N];
int nck(int n, int k) {
   return (fact[n] * inv((fact[k] * fact[n - k]) % mod) % mod) % mod;
}

void solve() {
   int n, s, g;
   cin >> n >> s >> g;
   if (s % g != 0 || s / g < n) {
      cout << 0 << endl;
      return;
   }
   int t = s / g;

   if (t % n != 0) {
      int x = t % n;
      cout << nck(n, x) << endl;
      return;
   }
   if (t / n == 1) {
      cout << 1 << endl;
      return;
   }
   if (n == 2 && ((t / n) & 1)) {
      cout << 2 << endl;
      return;
   }
   int res = 0;
   for (int n1 = 1; n1 <= (n - (t / n) % 2) / 2; n1++) {
      res +=
          fact[n] * inv((fact[n1] * fact[n1] % mod * fact[n - 2 * n1]) % mod);
      res %= mod;
   }
   cout << res << endl;
}

/*
6
2 6 15
1 15 5
2 15 2
2 16 2
2 6 1
1 15 6
0
0
0
2
2
0
*/

signed main() {
   ios::sync_with_stdio(false);
   cin.tie(0);

   fact[0] = 1;
   for (int i = 1; i < N; i++) {
      fact[i] = fact[i - 1] * i;
      fact[i] %= mod;
   }

   int tt = 1;
   cin >> tt;
   while (tt--) {
      solve();
   }
}