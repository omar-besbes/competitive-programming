#include <bits/stdc++.h>
using namespace std;
#define input "input.in"
#define output "output.out"

bool ask(int y) {
   cout << "? " << y << "\n";
   cout.flush();
   string ans;
   cin >> ans;
   return ans == "YES";
}

void answer(int y) {
    cout << "! " << y << "\n";
    cout.flush();
}

void solve() {
   int l = 1, r = 1e9, m = l;
   while (l < r) {
      m = (l + r) / 2;
      if (ask(m)) {
         l = m + 1;
      } else {
         r = m;
      }
   }
   answer(l);
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
