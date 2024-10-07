#include "bits/stdc++.h"
using namespace std;

long long ans;
vector<int> a;
int n;

void mad() {
   map<int, int> occ;
   int mad = 0;
   for (int i = 0; i < n; i++) {
      occ[a[i]]++;
      ans += a[i];
      mad = a[i] > mad && occ[a[i]] > 1 ? a[i] : mad;
      a[i] = mad;
   }
}

void solve() {
   cin >> n;
   ans = 0;
   a.assign(n, 0);
   for (int i = 0; i < n; i++) {
      cin >> a[i];
   }

   mad();
   mad();

   map<int, int> occ;
   for (int i = 0; i < n; i++) {
      occ[a[i]]++;
   }

   long long cumOcc = 0;
   for (auto [k, v] : occ) {
      long long currOcc = v, value = k;
      cumOcc += currOcc;
      ans += currOcc * (currOcc + 1) / 2 * value;
      ans += (n - cumOcc) * currOcc * value;
   }

   cout << ans << "\n";
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);

   int t;
   cin >> t;
   while (t--) solve();
}