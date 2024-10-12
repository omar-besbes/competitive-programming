#include <bits/stdc++.h>
using namespace std;

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);

   int n;
   cin >> n;
   vector<int> a(n);
   for (auto &i : a) cin >> i;

   stack<int> sr, sl;
   for (int b = 0; b < 32; b++) {
      for (int i = 0; i < n; i++)
         if (a[i] & (1 << b))
            sr.push(a[i]);
         else
            sl.push(a[i]);

      int i = n - 1;
      while (!sr.empty()) a[i--] = sr.top(), sr.pop();
      while (!sl.empty()) a[i--] = sl.top(), sl.pop();
   }

   for (auto i : a) cout << i << " ";
}