#include <bits/stdc++.h>
using namespace std;
#define input "input.in"
#define output "output.out"

void print(int src, int dst) { cout << src << " " << dst << "\n"; }

void move(int src, int dst, int d) {
   if (d <= 1) {
      print(src, dst);
      return;
   }

   int other = 6 - src - dst;
   move(src, other, d - 1);
   print(src, dst);
   move(other, dst, d - 1);
}

void solve() {
   int n;
   cin >> n;
   int k = (1 << n) - 1;
   cout << k << "\n";
   move(1, 3, n);
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
