#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

struct T {
   struct node {
      int next[26];
      bool terminal;
      node() {
         for (int i = 0; i < 26; i++) next[i] = -1;
         terminal = false;
      }
   };
   vector<node> st;

   T() { st.emplace_back(); }

   void insert(string &s) {
      int n = s.length();
      int cur = 0;
      for (int i = 0; i < n; i++)
         if (st[cur].next[s[i] - 'a'] == -1) {
            st[cur].next[s[i] - 'a'] = st.size();
            cur = st.size();
            st.emplace_back();
         } else
            cur = st[cur].next[s[i] - 'a'];
      st[cur].terminal = true;
   }

   int search(string &s) {
      int n = s.length();
      vector<int> dp(n + 1);
      dp[0] = 1;
      for (int len = 1; len <= n; len++) {
         int cur = 0;
         for (int i = n - len; i < n; i++) {
            if (st[cur].next[s[i] - 'a'] == -1) break;
            cur = st[cur].next[s[i] - 'a'];
            if (st[cur].terminal) dp[len] = (dp[len] + dp[n - (i + 1)]) % mod;
         }
      }
      return dp[n];
   }
};

void solve() {
   string s;
   cin >> s;
   int k;
   cin >> k;
   T t;
   while (k--) {
      string x;
      cin >> x;
      t.insert(x);
   }

   cout << t.search(s) << "\n";
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);

   int t = 1;
   // cin >> t;
   while (t--) solve();
}