#include <bits/stdc++.h>
#define MOD 998244353;
using namespace std;

int main() {
   //    ios::sync_with_stdio(false);
   //    cin.tie(nullptr);
   //    cout.tie(nullptr);
   //    freopen("challenge.in", "r", stdin);
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w+", stdout);

   int n, k, last = n + 2 * (k + 1), result = 1;
   cin >> n >> k;
   int b[n], lower[n];
   for (int i = 0; i < n; ++i) cin >> b[i];

   vector<int> Choices[n];
   for (int i = 0; i < n; ++i) {
      lower[i] = max(0, b[i] - k);
      int upper = b[i] + k, count = 0;
      for (int j = lower[i]; j <= n; ++j) Choices[i].push_back(j);
      if (b[i] + k <= last) {
         Choices[i].erase(Choices[i].begin());
         last = b[i] + k;
      }
      result *= (int)Choices[i].size();
      result %= MOD;
   }

   cout << result;

   return 0;
}