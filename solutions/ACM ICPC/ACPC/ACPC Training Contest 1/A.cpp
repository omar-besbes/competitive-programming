#include <bits/stdc++.h>
using namespace std;

int main() {
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   freopen("challenge.in", "r", stdin);
   // freopen("input.txt.txt", "r", stdin);
   int t;
   cin >> t;
   while (t--) {
      int N, indexWinner, maxRepition = 0, Repition = 0, lastIndex;
      cin >> N;
      int Rounds[N];
      for (int i = 0; i < N; ++i) {
         cin >> Rounds[i];
      }
      sort(Rounds, Rounds + N);
      indexWinner = Rounds[0];
      lastIndex = Rounds[0];
      for (int i = 1; i < N; ++i) {
         if (lastIndex == Rounds[i]) {
            Repition = 1;
            while (i < N && lastIndex == Rounds[i]) {
               Repition++;
               i++;
            }
            i--;
            if (maxRepition < Repition) {
               maxRepition = Repition;
               indexWinner = lastIndex;
            }
         } else {
            lastIndex = Rounds[i];
         }
      }
      cout << indexWinner << '\n';
   }
}
