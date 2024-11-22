#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e6 + 3;
ll nextu[N];
ll vis[N];

void dfs(int n, vector<ll>& v) {
   if (vis[n]) return;
   vis[n] = 1;
   v.push_back(n);
   dfs(nextu[n], v);
}

void solve() {
   ll n, x;
   cin >> n >> x;
   ll a[n];

   for (int i = 0; i < n; i++) cin >> a[i];
   sort(a, a + n, greater<ll>());

   ll start = 0, mini = 0, end = 0;

   while (end < n - 1) {
      // cout << start << " " << end << endl;
      if ((a[end + 1] + x) <= a[start]) {
         nextu[start] = end + 1;
         start++;
         end++;
      } else {
         end++;
      }
   }
   // for (int i = 0; i < n; i++) cout << nextu[i] << " ";
   vector<vector<ll>> aa;
   for (int i = 0; i < n; i++) {
      vector<ll> v;
      dfs(i, v);
      if (v.size() > 0) {
         aa.push_back(v);
      }
   }
   cout << aa.size() << endl;
   for (auto& y : aa) {
      cout << y.size() << " ";
      for (int i : y) {
         cout << a[i] << " ";
      }
      cout << endl;
   }
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);

   int t = 1;
   // cin >> t;
   while (t--) {
      solve();
   }

   return 0;
}