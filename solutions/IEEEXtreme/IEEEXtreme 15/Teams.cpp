#include <bits/stdc++.h>
using namespace std;

int L, C;
bool addition(bool g[], bool h[], bool k[]) {
   for (int i = 0; i < C; i++)
      if (!(g[i] || h[i] || k[i])) return false;
   return true;
}

int main() {
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   // freopen("pack.in", "r", stdin);
   freopen("input.txt.txt", "r", stdin);

   int t;
   cin >> t;
   while (t--) {
      cin >> L >> C;
      bool g[L][C];
      for (int i = 0; i < L; i++) {
         string x;
         cin >> x;
         for (int j = 0; j < C; j++) {
            if (x[j] == 'y')
               g[i][j] = true;
            else
               g[i][j] = false;
         }
      }

      int nbWays = 0;
      for (int i = 0; i < L; i++)
         for (int j = i + 1; j < L; j++)
            for (int k = j + 1; k < L; k++)
               if (addition(g[i], g[j], g[k])) nbWays++;
      cout << nbWays << '\n';
   }

   return 0;
}
