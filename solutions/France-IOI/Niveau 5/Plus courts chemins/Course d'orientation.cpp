#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);

   int n, a;
   cin >> n >> a;

   vector<map<int, int>> adj(n);
   for (int i = 0; i < a; i++) {
      int a, b, d;
      cin >> a >> b >> d;
      adj[a - 1][b - 1] = d;
   }

   vector<int> d(n, INT_MAX);
   d[0] = 0;
   bool test = false;
   for (int i = 0; i < n; i++) {
      test = false;
      for (int v = 0; v < n; v++) {
         for (auto e : adj[v]) {
            if (d[v] < INT_MAX && d[v] + e.second < d[e.first])
               d[e.first] = d[v] + e.second, test = true;
         }
      }
      if (!test) break;
   }

   if (!test)
      cout << d.back();
   else
      cout << "ERREUR";
}