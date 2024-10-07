#include "bits/stdc++.h"
using namespace std;

const int MAX_N = 2 * 1e5 + 1;

vector<long long> p3;

void solve() {
   long long l, r;
   cin >> l >> r;

   int start = 1, end = p3.size();
   long long res = 1;
   for (int i = 1; i < p3.size(); i++) {
      if (p3[i - 1] < l && l <= p3[i]) start = i, res = i;
      if (p3[i - 1] < r && r <= p3[i]) end = i + 1;
   }

   // cout << start << " " << end << " " << res << " ";
   for (int i = start; i <= end; i++)
      res += max(0ll, min(r, p3[i] - 1) - max(l, p3[i - 1]) + 1) * max(i, 1);

   cout << res << "\n";
}

void gen() {
   p3.push_back(1);
   while (p3.back() * 3 < MAX_N) p3.push_back(p3.back() * 3);
   p3.push_back(MAX_N);
}

int main() {
   gen();

   int t;
   cin >> t;
   while (t--) solve();
}