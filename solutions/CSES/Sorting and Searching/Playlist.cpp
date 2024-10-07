#include <bits/stdc++.h>
using namespace std;

int main() {
   int n, ans = 1;
   cin >> n;
   deque<int> seq;
   set<int> v;
   int curr;
   cin >> curr;
   seq.push_back(curr);
   v.insert(curr);
   for (int i = 0; i < n - 1; i++) {
      cin >> curr;
      if (v.find(curr) == v.end())
         v.insert(curr), seq.push_back(curr), ans = max(ans, (int)seq.size());
      else {
         while (seq.front() != curr) v.erase(seq.front()), seq.pop_front();
         seq.pop_front();
         seq.push_back(curr);
      }
   }

   cout << ans << "\n";
}