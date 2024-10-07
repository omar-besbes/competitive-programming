#include <bits/stdc++.h>
using namespace std;

int main() {
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

   int N, R, temp;
   cin >> N >> R;
   int suffixe[N];
   for (int i = 0; i < N; i++) {
      cin >> temp;
      if (i)
         suffixe[i] = suffixe[i - 1] + temp;
      else
         suffixe[0] = temp;
   }

   for (int i = 0; i < R; i++) {
      int D, F;
      cin >> D >> F;
      F--;
      D--;
      cout << suffixe[F] - suffixe[D - 1] << endl;
   }
}