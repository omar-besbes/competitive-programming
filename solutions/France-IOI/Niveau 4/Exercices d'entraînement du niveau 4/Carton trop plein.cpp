#include <bits/stdc++.h>
using namespace std;

int maxi = 0;
void explore(pair<vector<int>, bool> *R, int pos) {
   if (R[pos].second) return;
   R[pos].second = true;
   maxi = max(maxi, (int)R[pos].first.size());
   for (auto i : R[pos].first) {
      explore(R, i);
   }
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);

   int N, r;
   cin >> N;
   pair<vector<int>, bool> recipient[N + 1];
   for (int i = 0; i < N; ++i) {
      cin >> r;
      recipient[r].first.push_back(i + 1);
      recipient[r].second = false;
   }
   explore(recipient, 0);
   cout << maxi;

   return 0;
}