#include <bits/stdc++.h>
using namespace std;

int main() {
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   // freopen("pack.in", "r", stdin);
   freopen("input.txt.txt", "r", stdin);

   long long P, Q, N, M, sum = 0;
   cin >> P >> Q >> N >> M;
   for (long long i = 1; i <= N; i++) sum += (int)pow(P, i) * (int)pow(i, Q);
   sum %= M;
   cout << sum;

   return 0;
}