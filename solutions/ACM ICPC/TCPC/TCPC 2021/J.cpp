#include <bits/stdc++.h>
using namespace std;
int a[1005][1005], b[1005][1005], cu[1005][1005], cu1[10005][1005];
int n;
void rotate() {
   for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++) cu1[i][j] = cu[j][n - 1 - i];
   for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++) cu[i][j] = cu1[i][j];
}
void paint() {
   for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
         if (a[i][j]) cu[i][j] = 1;
}
bool compare() {
   for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
         if (cu[i][j] != b[i][j]) return false;
   return true;
}
int main() {
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   freopen("artwork.in", "r", stdin);
   // freopen("input.txt.txt", "r", stdin);
   int t;
   cin >> t;
   while (t--) {
      cin >> n;
      for (int i = 0; i < n; i++)
         for (int j = 0; j < n; j++) b[i][j] = 0;
      for (int i = 0; i < n; i++)
         for (int j = 0; j < n; j++) cin >> a[i][j];
      for (int i = 0; i < n; i++)
         for (int j = 0; j < n; j++) cin >> b[i][j];
      bool found = 0;
      for (int i = 0; i < (1 << 4) && !found; i++) {
         for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) cu[i][j] = 0;
         for (int j = 0; j < 4; j++) {
            if (i & (1 << j)) paint();
            rotate();
         }
         for (int j = 0; j < 4; j++) {
            if (compare()) found = 1;
            rotate();
         }
      }
      if (found)
         cout << "YES\n";
      else
         cout << "NO\n";
   }
}
