#include <bits/stdc++.h>
#define MAX_NB_COINS 100
#define MAX_MONEY 1000000
#define MOD 1000000007
using namespace std;

int n, nbCombinations[MAX_MONEY + 1];
vector<int> Coin;
int CalculCombinations(int x) {
   if (nbCombinations[x] > 0) return nbCombinations[x];
   for (int i = 0; x >= Coin[i] && i < n; ++i) {
      nbCombinations[x] += CalculCombinations(x - Coin[i]);
      nbCombinations[x] %= MOD;
   }
   return nbCombinations[x];
}

int main() {
   //    freopen("challenge.in", "r", stdin);
   //    freopen("input.txt", "r", stdin);
   //    freopen("output.txt", "w", stdout);

   int x;
   cin >> n >> x;
   for (int i = 0; i < x; ++i) {
      nbCombinations[i + 1] = 0;
   }
   for (int i = 0; i < n; ++i) {
      int y;
      cin >> y;
      Coin.push_back(y);
   }
   sort(Coin.begin(), Coin.end());
   nbCombinations[0] = 1;
   nbCombinations[Coin[0]] = 1;
   cout << CalculCombinations(x);

   return 0;
}