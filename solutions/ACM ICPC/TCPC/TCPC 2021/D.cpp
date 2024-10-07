#include <bits/stdc++.h>
using namespace std;

int main() {
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   freopen("min.in", "r", stdin);
   // freopen("input.txt.txt", "r", stdin);
   /*
   int t=1;
   cin >> t;
   while(t--) {

   }
    */
   int N;
   cin >> N;
   int arr[N], currentSum = 0, minSum;
   for (int i = 0; i < N; i++) cin >> arr[i];
   sort((arr), arr + N);
   for (int i = 1; i < N / 2; i++) currentSum += arr[i] - arr[i - 1];
   minSum = currentSum;
   for (int i = 1; i + N / 2 - 1 < N; i++) {
      currentSum -= (arr[i] - arr[i - 1]);
      currentSum += (arr[i + N / 2 - 1] - arr[i + N / 2 - 2]);
      minSum = min(minSum, currentSum);
   }
   cout << minSum;
}
