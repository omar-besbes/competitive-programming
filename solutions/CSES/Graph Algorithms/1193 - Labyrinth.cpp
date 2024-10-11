#include <bits/stdc++.h>
using namespace std;

pair<int, int> operator+(pair<int, int> const &a, pair<int, int> &b) {
   pair<int, int> c;
   c.first = a.first + b.first;
   c.second = a.second + b.second;
   return c;
}

bool operator==(pair<int, int> const &a, pair<int, int> &b) {
   return a.first == b.first && a.second == b.second;
}

int n, m;
int s[1000][1000];
pair<int, int> start, ending;
pair<int, int> d[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
char di[4] = {'U', 'R', 'D', 'L'};
char dj[4] = {'d', 'l', 'u', 'r'};
deque<char> path;
queue<pair<pair<int, int>, int>> q;

bool verify(pair<int, int> a) {
   if (a.first < 0 || a.second < 0 || a.first >= n || a.second >= m)
      return false;
   if (s[a.first][a.second] != -'A' && s[a.first][a.second] != -'B' &&
       s[a.first][a.second] != -'.')
      return false;
   return true;
}

void reconstitute(pair<int, int> a) {
   if (a.first < 0 || a.second < 0 || a.first >= n || a.second >= m) return;
   for (int i = 0; i < 4; ++i) {
      if (!((a + d[i]).first < 0 || (a + d[i]).second < 0 ||
            (a + d[i]).first >= n || (a + d[i]).second >= m))
         if (s[(a + d[i]).first][(a + d[i]).second] ==
             s[a.first][a.second] - 1) {
            path.push_front(dj[i]);
            reconstitute(a + d[i]);
            return;
         }
   }
}

void propagate(pair<int, int> &a, int depth) {
   if (!verify(a)) return;
   s[a.first][a.second] = depth;
   if (a == ending) {
      reconstitute(a);
      while (q.size() > 1) q.pop();
      return;
   }
   for (auto &i : d) {
      for (int j = 0; j < 4; ++j) {
         q.push((make_pair(a + i, depth + 1)));
      }
   }
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);

   cin >> n >> m;
   for (int i = 0; i < n; ++i) {
      string st;
      cin >> st;
      for (int j = 0; j < m; ++j) {
         s[i][j] = -st[j];
         if (s[i][j] == -'A') start = make_pair(i, j);
         if (s[i][j] == -'B') ending = make_pair(i, j);
      }
   }

   q.push(make_pair(start, 0));
   while (!q.empty()) {
      propagate(q.front().first, q.front().second);
      q.pop();
      //		for (int i = 0; i < n; ++i) {
      //			for (int j = 0; j < m; ++j) {
      //				if (s[i][j] < 0) {
      //					char x = -s[i][j];
      //					cout << x << " ";
      //				} else cout << (s[i][j] > n * m ?
      // INT_MAX - s[i][j] : s[i][j]) << " ";
      //			}
      //			cout << "\n";
      //		}
      //		cout << "\n";
   }
   if (path.empty())
      cout << "NO\n";
   else {
      cout << "YES\n" << path.size() << "\n";
      for (const auto &item : path) cout << (char)toupper(item);
   }

   return 0;
}