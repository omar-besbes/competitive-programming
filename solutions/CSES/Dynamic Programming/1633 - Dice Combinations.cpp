#include <bits/stdc++.h>
#define MAX_ANSWER 1000000
#define MOD 1000000007
using namespace std;

long long n, ans[MAX_ANSWER];
long long buildAnswer(int num) {
   long long answer = 0;
   for (int i = 0; i < 6; ++i) {
      if (!ans[num - i - 2]) ans[num - i - 2] = buildAnswer(num - i - 1) % MOD;
      answer += ans[num - i - 2];
   }
   return answer % MOD;
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);
   //    freopen("challenge.in", "r", stdin);
   //    freopen("input.txt", "r", stdin);
   //    freopen("output.txt", "w+", stdout);

   cin >> n;
   ans[0] = 1;
   ans[1] = 2;
   ans[2] = 4;
   ans[3] = 8;
   ans[4] = 16;
   ans[5] = 32;
   if (n < 7)
      cout << ans[n - 1];
   else
      cout << buildAnswer(n);

   return 0;
}