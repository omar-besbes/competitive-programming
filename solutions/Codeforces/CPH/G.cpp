#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<int, int> &a, pair<int, int> &b) {
   if (a.second == b.second) return a.first < b.first;
   return a.second < b.second;
}

int main() {
   //    ios::sync_with_stdio(false);
   //    cin.tie(nullptr);
   //    cout.tie(nullptr);
   //    freopen("name.in", "r", stdin);
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w+", stdout);

   int n, m;
   cin >> n;
   vector<pair<int, int>> a;
   int s[n];
   for (int i = 0; i < n; ++i) {
      cin >> s[i];
   }
   cin >> m;
   int b[m], c[m];
   for (int i = 0; i < m; ++i) {
      cin >> b[i];
   }
   for (int i = 0; i < m; ++i) {
      cin >> c[i];
   }
   sort(s, s + n);
   int i = 1;
   while (i < n) {
      int begin = i - 1;
      while (i < n && s[i] == s[i - 1]) i++;
      a.emplace_back(s[i - 1], i - begin);
   }
   sort(a.begin(), a.end(), cmp);

   i = 0;
   bool found = false;
   while (!found && i < a.size()) {
      vector<pair<int, int>> s;
      for (int j = 0; j < m; ++j) {
         if (a[i].first == b[j]) {
            s.emplace_back(j, c[j]);
            found = true;
         }
      }

      if (found) {
         int j = 0;
         auto index = s.end();
         while ((index = find_if(s.begin(), s.end(),
                                 [&a, j](pair<int, int> &x) {
                                    return (a[j].first == x.second);
                                 })) == s.end() &&
                j < m)
            j++;
         cout << index->first + 1;
      }

      i++;
   }

   return 0;
}