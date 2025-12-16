#include <bits/stdc++.h>
using namespace std;
#define input "input.in"
#define output "output.out"

bool ask(int i, int j) {
   cout << "? " << i + 1 << " " << j + 1 << "\n";
   cout.flush();
   string ans;
   cin >> ans;
   return ans == "YES";
}

void answer(vector<int>& p) {
   cout << "! ";
   vector<int> ans(p.size());
   for (int i = 0; i < p.size(); i++) {
      ans[p[i]] = i + 1;
   }
   for (int i = 0; i < ans.size(); i++) {
      cout << ans[i] << " ";
   }
   cout << "\n";
   cout.flush();
}

int find_insertion_position(vector<int>& p, int i) {
   int l = 0, r = p.size();
   while (l < r) {
      int m = (l + r) / 2;
      if (ask(p[m], i)) {
         l = m + 1;
      } else {
         r = m;
      }
   }
   return l;
}

void print(vector<int>& p) {
   cout << "\n";
   for (auto i : p) cout << i << " ";
   cout << "\n";
}

void solve() {
   int n;
   cin >> n;
   vector<int> p;
   for (int i = 0; i < n; i++) {
      int idx = find_insertion_position(p, i);
      p.insert(p.begin() + idx, i);
      // print(p);
   }

   answer(p);
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);

   if (fopen(input, "r")) freopen(input, "r", stdin);
   if (fopen(output, "r")) freopen(output, "w+", stdout);

   int t = 1;
   // cin >> t;
   while (t--) solve();
}
