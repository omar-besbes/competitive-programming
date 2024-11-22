#include <bits/stdc++.h>
#pragma GCC optimization ("O2")
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;

struct Hashing {
   vector<vector<ll>> p, pref;
   // assuming s is only composed of a-z characters
   Hashing(const string &s) {
      int n = s.length();
      // change if s contains other chars than a-z
      // primes should be greater than number of possible characters
      vector primes{31, 37};
      p.assign(primes.size(), vector<ll>(n + 1));
      pref.assign(primes.size(), vector<ll>(n + 1));
      for (int i = 0; i < primes.size(); i++) p[i][0] = 1, p[i][1] = primes[i];
      for (int i = 0; i < p.size(); i++) {
         p[i].resize(n + 1);
         for (int j = 0; j < n; j++) {
            // change here if s contains other chars than a-z
            int c = s[j] - 'a' + 1;
            pref[i][j + 1] = (pref[i][j] + c * p[i][j]) % mod;
            p[i][j + 1] = p[i][j] * p[i][1] % mod;
         }
      }
   }
   // hash of s[l..r] inclusive for l & r
   vector<ll> get(int l, int r) {
      int n = p[0].size() - 1;
      vector<ll> ans(p.size());
      for (int i = 0; i < p.size(); i++) {
         ans[i] = (pref[i][r + 1] - pref[i][l] + mod) % mod;
         ans[i] = ans[i] * p[i][n - l] % mod;
      }
      return ans;
   }
   bool compare(pair<int, int> r1, pair<int, int> r2) {
      auto res1 = get(r1.first, r1.second);
      auto res2 = get(r2.first, r2.second);
      for (int i = 0; i < p.size(); i++)
         if (res1[i] != res2[i]) return false;
      return true;
   }
};

int main() {
   string s;
   cin >> s;
   int n = s.length();
   auto h = Hashing(s);
   unordered_map<ll, vector<pair<int, int>>> a;
   unordered_map<ll, int> sz;
   for (int r = 0; r < n; r++) {
      for (int l = 0; l <= r; l++) {
         auto tmp = h.get(l, r);
         ll hash = tmp[0] + mod * tmp[1];
         sz[hash] = r - l + 1;
         a[hash].push_back({l, r});
      }
   }

   auto getNbComponents = [&](vector<pair<int, int>> &a) {
      sort(a.begin(), a.end());
      int curl = 0, curr = 0, ans = 1;
      for (auto [l, r] : a) {
         if (l > curr) {
            ans += l - curr;
            curl = l, curr = r;
         } else {
            curr = max(curr, r);
         }
      }
      ans += (n - 1) - curr;
      return ans;
   };

   vector<vector<int>> v(n + 1);
   for (auto [hash, ranges] : a) {
      v[sz[hash]].push_back(getNbComponents(ranges));
   }

   vector<int> ans(n + 1, 0);
   for (int len = n; len >= 0; len--) {
      for (auto nb : v[len]) {
         ans[nb] = len;
      }
   }

   for (int i = 1; i <= n; i++) cout << ans[i] << " ";
}