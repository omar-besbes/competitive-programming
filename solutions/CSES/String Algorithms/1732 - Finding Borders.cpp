#include "bits/stdc++.h"
using namespace std;

int main() {
   string s;
   cin >> s;
   int n = s.length();
   vector<int> pi(n);
   for (int i = 1; i < n; i++) {
      int j = pi[i - 1];
      while (j && s[i] != s[j]) j = pi[j - 1];
      pi[i] = j ? j + 1 : s[i] == s[j];
   }

   vector<int> ans;
   int i = pi[n - 1];
   while (i) ans.push_back(i), i = pi[i - 1];

   for (auto i = ans.rbegin(); i != ans.rend(); i++) cout << *i << " ";
}