#include "bits/stdc++.h"
using namespace std;

int main() {
   int id;
   cin >> id;
   int n;
   cin >> n;
   map<int, set<int>> m;
   set<int> amis;
   for (int i = 0; i < n; i++) {
      int a, b;
      cin >> a >> b;
      m[a].insert(b);
      m[b].insert(a);
   }

   queue<int> q;
   for (auto &c : m[id]) q.push(c);
   while (!q.empty()) {
      int front = q.front();
      q.pop();

      // if already counted, don't continue
      if (front != id && amis.find(front) == amis.end()) {
         amis.insert(front);
         // only explore direct friends
         if (m[id].find(front) != m[id].end())
            for (auto &c : m[front]) q.push(c);
      }
   }

   cout << amis.size() - m[id].size() << "\n";

   return 0;
}