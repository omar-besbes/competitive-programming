#include <bits/stdc++.h>
#define MAX_NUMBER 1000000
using namespace std;

int n, dp[MAX_NUMBER + 1];
int remove(int x) {
   if (!x || dp[x]) return dp[x];
   int digit = x % 10, i = x;
   while (i) {
      if (digit) {
         if (dp[x])
            dp[x] = min(remove(x - digit) + 1, dp[x]);
         else
            dp[x] = remove(x - digit) + 1;
      }
      i /= 10;
      digit = i % 10;
   }
   return dp[x];
}

int main() {
   //    ios::sync_with_stdio(false);
   //    cin.tie(nullptr);
   //    cout.tie(nullptr);
   //    freopen("challenge.in", "r", stdin);
   //    freopen("input.txt", "r", stdin);
   //    freopen("output.txt", "w+", stdout);

   cin >> n;
   for (int i = 0; i <= n; ++i) dp[i] = 0;
   cout << remove(n);

   return 0;
}