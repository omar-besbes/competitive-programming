#include <bits/stdc++.h>
using namespace std;

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);

   int n;
   cin >> n;
   vector<int> cnt(2e5 + 1);
   for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      cnt[x + 1e5]++;
   }

   for (int i = 0; i < 2e5 + 1; i++)
      while (cnt[i]--) cout << i - 1e5 << " ";
}