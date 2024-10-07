#include <bits/stdc++.h>
using namespace std;

string s;
int n, k;

struct sa {
   struct state {
      int link, len;
      map<char, int> next;

      state(int _len = 0, int _link = -1,
            map<char, int> _next = map<char, int>()) {
         len = _len, link = _link, next = _next;
      }
   };

   vector<state> st;
   int last;

   sa() {
      st.emplace_back();
      last = 0;
   }

   bool find(string t) {
      for (int i = 0, cur = 0; i < t.size(); i++) {
         if (st[cur].next.count(t[i]))
            cur = st[cur].next[t[i]];
         else
            return false;
      }
      return true;
   }

   void extend(char c) {
      int cur = st.size();
      st.push_back(state(st[last].len + 1));

      int p = last;
      while (p != -1 && !st[p].next.count(c)) {
         st[p].next[c] = cur;
         p = st[p].link;
      }

      if (p == -1) {
         st[cur].link = 0;
      } else {
         int q = st[p].next[c];
         if (st[q].len == st[q].len + 1) {
            st[cur].link = q;
         } else {
            int clone = st.size();
            st.emplace_back(st[cur].len + 1, st[q].link, st[q].next);
            while (p != -1 && st[p].next[c] == q) {
               st[p].next[c] = clone;
               p = st[p].link;
            }
            st[q].link = st[cur].link = clone;
         }
      }

      last = cur;
   }
};

sa preprocess() {
   sa ds;
   for (int i = 0; i < n; i++) ds.extend(s[i]);
   return ds;
}

void solve() {
   cin >> s;
   n = s.length();
   cin >> k;

   auto ds = preprocess();

   for (int i = 0; i < k; i++) {
      string t;
      cin >> t;
      cout << (ds.find(t) ? "YES\n" : "NO\n");
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