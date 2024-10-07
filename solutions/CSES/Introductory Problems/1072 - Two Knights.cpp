#include <bits/stdc++.h>
using namespace std;

int main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);

   int n;
   cin >> n;
   vector<long long> v = {0, 6, 28, 96};
   long long outer = 8, middle = 4, center = 1, ans;
   for (int i = 5; i <= n; ++i) {
      ans =
          (4 * (i * i - 1 - 2) + 8 * (i * i - 1 - 3) + outer * (i * i - 1 - 4) +
           middle * (i * i - 1 - 6) + center * (i * i - 1 - 8)) /
          2;
      v.push_back(ans);
      outer += 4;
      middle += 4;
      center += (i - 4) * 2 + 1;
   }
   for (int i = 0; i < n; ++i) cout << v[i] << "\n";

   return 0;
}