#include "bits/stdc++.h"
using namespace std;

const int RULER_LENGTH = 999;

void solve() {
   int start = 0, end = RULER_LENGTH;
   int l = end / 3, r = 2 * end / 3, ans;
   while (end - start > 3) {
      cout << "? " << l << " " << r << "\n" << flush;
      cin >> ans;

      if (ans == l * r)
         start = r;
      else if (ans == l * (r + 1))
         start = l, end = r;
      else
         end = l;

      int tmp = (end - start) / 3;
      l = start + tmp;
      r = end - tmp;
   }

   while (start <= end) {
      cout << "? " << start << " " << start << "\n" << flush;
      cin >> ans;

      if (ans != start * start) break;

      start++;
   }

   cout << "! " << start << "\n" << flush;
}

int main() {
   int t;
   cin >> t;
   while (t--) solve();
}