#include <bits/stdc++.h>
using namespace std;
#define input "input.in"
#define output "output.out"

void solve() {
   int n;
   cin >> n;

   if (n == 1) {
      cout << "1";
      return;
   }

   if (n <= 3) {
      cout << "NO SOLUTION";
      return;
   }

   list<int> v{3, 1, 4, 2};
   for (auto i = 5; i <= n; i++) {
      if (i & 1)
         v.push_back(i);
      else
         v.push_front(i);
   }

   for (auto i : v) cout << i << " ";
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);

   if (fopen(input, "r")) freopen(input, "r", stdin);
   if (fopen(output, "r")) freopen(output, "w+", stdout);

   int t = 1;
   // cin >> t;
   while (t--) solve();
}
