#include <bits/stdc++.h>
using namespace std;

int main() {
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   freopen("circles.in", "r", stdin);
   // freopen("input.txt.txt", "r", stdin);
   int t;
   cin >> t;
   while (t--) {
      int x1, x2, y1, y2, x3, y3;
      cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
      int det = (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1);
      if (det == 0)
         cout << "Impossible\n";
      else
         cout << "Possible\n";
   }
}
