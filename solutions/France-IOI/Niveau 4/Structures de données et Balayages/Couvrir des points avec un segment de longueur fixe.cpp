#include "bits/stdc++.h"

using namespace std;

int main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);

   int L, N, debut = 0, maxi = 1;
   cin >> L >> N;
   int point[N];
   for (int fin = 0; fin < N; ++fin) cin >> point[fin];
   sort(point, point + N);
   for (int fin = 1; fin < N; ++fin) {
      if (point[fin] - point[debut] > L) {
         while (point[fin] - point[debut] > L && fin > debut) debut++;
         if (debut == fin) continue;
      }
      maxi = max(maxi, fin - debut + 1);
   }

   cout << maxi;

   return 0;
}