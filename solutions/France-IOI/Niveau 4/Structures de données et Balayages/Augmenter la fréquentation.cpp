#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int, double> p1, pair<int, double> p2) {
   if (p1.first == p2.first) return p1.second < p2.second;
   return p1.first < p2.first;
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);

   int N, limit;
   double Max;
   cin >> N;
   pair<int, double> S[N];
   for (int i = 0; i < N; i++) cin >> S[i].first >> S[i].second;
   sort(S, S + N, compare);

   for (int i = 1; i < N; ++i) S[i].second += S[i - 1].second;

   Max = S[0].second;
   limit = S[0].first;
   for (int i = 1; i < N; i++) {
      double temp = S[i].second / ((double)(i + 1));
      if (temp >= Max) {
         limit = S[i].first;
         Max = temp;
      }
   }
   cout << limit;
   return 0;
}