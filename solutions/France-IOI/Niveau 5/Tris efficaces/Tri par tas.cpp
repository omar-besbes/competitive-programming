#include "bits/stdc++.h"

using namespace std;

vector<int> h;

class Compare {
  public:
   bool operator()(int curr, int other) { return h[curr] > h[other]; }
};

void insert_heap(int x) {
   h.push_back(x);
   int index = h.size() - 1;
   while (index > 1 && h[index / 2] > h[index]) {
      swap(h[index / 2], h[index]);
      index /= 2;
   }
}

int main() {
   int n;
   cin >> n;
   h.push_back(1);
   for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      insert_heap(a);
   }

   priority_queue<int, vector<int>, Compare> s;
   s.push(1);
   while (!s.empty()) {
      int min_index = s.top();
      s.pop();
      cout << h[min_index] << " ";
      if (min_index * 2 < n + 1) s.push(min_index * 2);
      if (min_index * 2 + 1 < n + 1) s.push(min_index * 2 + 1);
   }
}
