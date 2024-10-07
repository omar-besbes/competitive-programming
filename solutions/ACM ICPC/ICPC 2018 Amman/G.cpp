#include <bits/stdc++.h>

using namespace std;

bool compare(pair<int, pair<int, long long>> &a,
             pair<int, pair<int, long long>> &b) {
   //    if(a.second.second == b.second.second) {
   //        return a.first < b.first;
   //    }
   return a.second.first < b.second.first;
}

int main() {
   //    ios::sync_with_stdio(false);
   //    cin.tie(nullptr);
   //    cout.tie(nullptr);
   //    freopen("name.in", "r", stdin);
   //    freopen("input.txt", "r", stdin);
   //    freopen("output.txt", "w+", stdout);

   int t;
   cin >> t;
   while (t--) {
      int n, k;
      string s;
      cin >> n >> k >> s;
      pair<int, pair<int, long long>> occ_score[26];
      for (int i = 0; i < 26; i++) {
         occ_score[i].first = 97 + i;
         occ_score[i].second = make_pair(0, 0);
      }

      for (int i = 0; i < n; ++i) {
         occ_score[s[i] - 97].second.first++;
      }

      long long total = 0;
      for (auto &i : occ_score) {
         i.second.second =
             i.second.first * (i.second.first - 1) * (i.first) / 2;
         total += i.second.second;
      }

      sort(occ_score, occ_score + 26, compare);

      if (k >= n) {
         cout << n * (n - 1) * 122 / 2 << '\n';  // tous z
      } else {
         if (k < n - occ_score[25].second.first) {
            total -= occ_score[25].second.second;
            total += (occ_score[25].second.first + k) *
                     (occ_score[25].second.first + k - 1) *
                     occ_score[25].first / 2;
         } else {
            int c = occ_score[25].first;
            int x = 24;
            while (k >= n - occ_score[x].second.first) {
               c = max(c, occ_score[x].first);
               x--;
            }
            total = n * (n - 1) * c / 2;
         }
      }

      cout << total << '\n';
   }

   return 0;
}