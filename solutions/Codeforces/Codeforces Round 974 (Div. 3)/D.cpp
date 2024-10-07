#include <bits/stdc++.h>
using namespace std;

void solve() {
   int n, d, k;
   cin >> n >> d >> k;
   vector<set<int>> job(n + 2);
   map<int, int> st, en;
   for (int i = 0; i < k; i++) {
      int l, r;
      cin >> l >> r;
      st[l]++;
      en[r]++;
   }

   int cur = 0;
   for (int i = 1; i <= d; i++) cur += st[i];

   pair<int, int> maxi{cur, 1}, mini{cur, 1};
   for (int i = d + 1; i <= n; i++) {
      cur += st[i];
      cur -= en[i - d];
      if (cur > maxi.first) maxi = make_pair(cur, i - d + 1);
      if (cur < mini.first) mini = make_pair(cur, i - d + 1);
   }

   cout << maxi.second << " " << mini.second << "\n";
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);

   int t = 1;
   cin >> t;
   while (t--) solve();
}