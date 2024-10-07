#include "bits/stdc++.h"
using namespace std;

int main() {
   int n;
   cin >> n;

   queue<int> q;
   for (int i = 0; i < n; i++) q.push(i + 1);

   while (!q.empty()) {
      q.push(q.front());
      q.pop();
      cout << q.front() << " ";
      q.pop();
   }

   return 0;
}