#include "bits/stdc++.h"
using namespace std;

const pair<int, int> d[] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int l, c;
vector<vector<char>> input;
vector<vector<int>> st;

void compute_weights() {
   priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                  greater<tuple<int, int, int>>>
       q;
   q.push(make_tuple(0, 1, 0));
   while (!q.empty()) {
      int ans, x, y;
      tie(ans, x, y) = q.top();
      q.pop();

      // out of bounds
      if (x < 0 || x >= l || y < 0 || y >= c) continue;
      // not crossable
      if (input[x][y] < '0') continue;

      // already reached this position with a lower score
      ans += input[x][y] - '0';
      if (st[x][y] <= ans) continue;
      st[x][y] = ans;

      for (auto di : d) {
         int dx, dy;
         tie(dx, dy) = di;
         auto next = make_tuple(ans, x + dx, y + dy);
         q.push(next);
      }
   }
}

void print() {
   for (int i = 0; i < l; i++) {
      for (int j = 0; j < c; j++) {
         cout << setw(10) << setfill('0') << st[i][j] << " ";
      }
      cout << "\n";
   }
}

int main() {
   ios::sync_with_stdio(false);

   cin >> l >> c;
   input.assign(l, vector<char>(c));
   st.assign(l, vector<int>(c, INT_MAX));
   for (int i = 0; i < l; i++) {
      string s;
      cin >> s;
      for (int j = 0; j < c; j++) input[i][j] = (s[j] == '.' ? '0' : s[j]);
   }
   compute_weights();
   // print();

   cout << st[l - 1][c - 2];
}