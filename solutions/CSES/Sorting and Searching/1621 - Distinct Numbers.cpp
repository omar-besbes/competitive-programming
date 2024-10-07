#include <bits/stdc++.h>
using namespace std;

int main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);

   int n;
   cin >> n;
   set<int> seti;
   for (int i = 0; i < n; ++i) {
      int x;
      cin >> x;
      seti.insert(x);
   }
   cout << seti.size() << "\n";

   return 0;
}
