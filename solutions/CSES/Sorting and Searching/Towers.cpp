#include <bits/stdc++.h>
using namespace std;

int main() {
   int n;
   cin >> n;
   vector<int> t;
   for (int i = 0; i < n; i++) {
      int curr;
      cin >> curr;
      auto idx = upper_bound(t.begin(), t.end(), curr);
      if (idx == t.end())
         t.push_back(curr);
      else
         *idx = curr;
   }

   cout << t.size() << "\n";
}