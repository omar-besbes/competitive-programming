#include <bits/stdc++.h>

using namespace std;

int main() {
   //    ios::sync_with_stdio(false);
   //    cin.tie(nullptr);
   //    cout.tie(nullptr);
   //    freopen("name.in", "r", stdin);
   //    freopen("input.txt", "r", stdin);
   //    freopen("output.txt", "w+", stdout);

   int n;
   cin >> n;
   vector<int> a, b;
   map<int, int> mapa, mapb;
   for (auto i : a) {
      cin >> i;
      mapa[i]++;
   }
   for (auto i : b) {
      cin >> i;
      mapb[i]++;
   }

   if (mapa.size() == mapb.size() &&
       equal(mapa.begin(), mapa.end(), mapb.begin()))
      cout << "Yes\n";
   else
      cout << "No\n";

   return 0;
}