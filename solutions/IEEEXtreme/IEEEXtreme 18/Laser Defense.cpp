#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

int l, n, m;

vector<int> readA() {
   vector<int> u, r;
   for (int i = 0; i < n; i++) {
      char type;
      int x;
      cin >> type >> x;
      if (type == 'U')
         u.push_back(x);
      else
         r.push_back(x + 1e9);
   }
   sort(all(u));
   sort(rall(r));
   vector<int> ans;
   ans.insert(ans.end(), u.begin(), u.end());
   ans.insert(ans.end(), r.begin(), r.end());
   return ans;
}

vector<int> readB() {
   vector<int> u, l;
   for (int i = 0; i < m; i++) {
      char type;
      int x;
      cin >> type >> x;
      if (type == 'U')
         u.push_back(x);
      else
         l.push_back(x - 1e9);
   }
   sort(all(u));
   sort(all(l));
   vector<int> ans;
   ans.insert(ans.end(), l.begin(), l.end());
   ans.insert(ans.end(), u.begin(), u.end());
   return ans;
}

int main() {
   cin >> l >> n >> m;
   auto a = readA();
   auto b = readB();
   reverse(all(a));

   long long ans = m + 1;
   for (auto i : a) {
      auto idx = lower_bound(all(b), i) - b.begin();
      int nb = idx + 1;
      ans += nb;
   }

   cout << ans << "\n";
}