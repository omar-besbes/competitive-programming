#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> merge(vector<pair<int, int>> must) {
   vector<pair<int, int>> ans;
   sort(must.begin(), must.end());
   if (must.empty()) return ans;
   int curl = must[0].first, curr = must[1].second;
   for (auto [l, r] : must) {
      if (l > curr + 1)
         ans.push_back({curl, curr}), curl = l, curr = r;
      else
         curr = max(curr, r);
   }
   ans.push_back({curl, curr});
   return ans;
}

void solve() {
   int n, q;
   cin >> n >> q;
   vector<int> a(n);
   for (auto &i : a) cin >> i;
   string s;
   cin >> s;

   vector<pair<int, int>> must;
   for (int i = 0; i < n; i++)
      if (a[i] != i + 1)
         must.push_back({min(a[i] - 1, i), max(a[i] - 1, i) - 1});
   must = merge(must);

   auto needindex = [&](int idx) {
      auto it = lower_bound(must.begin(), must.end(), make_pair(idx, idx));
      if (it == must.end() || it->first > idx) {
         if (it == must.begin()) return false;
         it--;
         if (it->second < idx)
            return false;
         else
            return true;
      } else {
         return true;
      }
   };

   set<int> toremove;
   for (int i = 0; i < n - 1; i++) {
      if (s[i] == 'L' && s[i + 1] == 'R' && needindex(i)) toremove.insert(i);
   }

   for (int i = 0; i < q; i++) {
      int idx;
      cin >> idx;
      idx--;
      s[idx] = s[idx] == 'L' ? 'R' : 'L';

      if (idx + 1 < n)
         if (s[idx] == 'L' && s[idx + 1] == 'R' && needindex(idx))
            toremove.insert(idx);
         else
            toremove.erase(idx);

      if (idx - 1 >= 0)
         if (s[idx - 1] == 'L' && s[idx] == 'R' && needindex(idx - 1))
            toremove.insert(idx - 1);
         else
            toremove.erase(idx - 1);

      cout << (toremove.empty() ? "YES" : "NO") << "\n";
   }
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);

   int t = 1;
   cin >> t;
   while (t--) solve();
}