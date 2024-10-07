#include <bits/stdc++.h>
#define MAX 200000
using namespace std;

vector<pair<int, vector<int>>> a(MAX + 1, make_pair(-1, vector<int>()));
int search(int e) {
   if (a[e].first != -1) return a[e].first;
   a[e].first = 0;
   for (auto v : a[e].second) {
      a[e].first += 1 + search(v);
   }
   return a[e].first;
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);

   int n;
   cin >> n;
   for (int i = 2; i <= n; ++i) {
      int x;
      cin >> x;
      a[x].second.push_back(i);
   }
   search(1);
   for (int i = 0; i < n; ++i) {
      cout << a[i + 1].first << " ";
   }

   return 0;
}