#include <bits/stdc++.h>
using namespace std;

int main() {
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   freopen("pack.in", "r", stdin);
   // freopen("input.txt.txt", "r", stdin);
   int t;
   cin >> t;
   while (t--) {
      int N, Q;
      cin >> N;
      int arr[N];
      for (int i = 0; i < N; i++) cin >> arr[i];
      cin >> Q;
      for (int q = 0; q < Q; q++) {
         bool resultat = true;
         int x, x_cnt, y, y_cnt;
         cin >> x >> x_cnt >> y >> y_cnt;
         int S[x_cnt + y_cnt];
         for (int i = 0; i < x_cnt + y_cnt; i++)
            if (i < x_cnt)
               S[i] = x;
            else
               S[i] = y;
         for (int i = 0; i < N && resultat; i++) {
            int j = 0;
            while (j < x_cnt + y_cnt && S[j] < arr[i] && resultat) j++;
            if (j >= x_cnt + y_cnt) {
               cout << "No" << '\n';
               resultat = false;
            } else
               S[j] -= arr[i];
         }
         if (resultat) cout << "Yes" << '\n';
      }
   }
}
