#include "bits/stdc++.h"

using namespace std;

int N;
vector<pair<int, int>> cables;

int compute_tree_size(int root, vector<vector<int>> &p, set<int> &a) {
   int res = 1;
   a.insert(root);
   for (auto &c : p[root]) {
      if (a.find(c) == a.end()) res += compute_tree_size(c, p, a);
   }
   a.erase(root);
   return res;
}

int brute_force() {
   vector<vector<int>> p(N, vector<int>(0));
   for (auto &c : cables) {
      p[c.first].push_back(c.second);
      p[c.second].push_back(c.first);
   }

   int maxi = 0;
   for (int i = 0; i < N; i++) {
      int max_child_size = 0;
      set<int> s;
      s.insert(i);
      for (auto &j : p[i])
         max_child_size = max(max_child_size, compute_tree_size(j, p, s));
      maxi = max(maxi, N - max_child_size);
   }

   return maxi;
}

int c_w(int a, int b, vector<vector<pair<int, int>>> &p) {
   int index = find_if(p[a].begin(), p[a].end(),
                       [b](auto &x) { return x.first == b; }) -
               p[a].begin();
   // already computed
   if (p[a][index].second) return p[a][index].second;
   // compute if not already computed
   int res = 1;
   for (auto &c : p[b]) {
      if (c.first != a) res += c_w(b, c.first, p);
   }
   p[a][index].second = res;
   return p[a][index].second;
}

int solve() {
   vector<vector<pair<int, int>>> p(N, vector<pair<int, int>>(0));
   for (auto &c : cables) {
      p[c.first].emplace_back(c.second, 0);
      p[c.second].emplace_back(c.first, 0);
   }

   // compute edges weights
   for (int i = 0; i < N; i++) {
      for (auto &d : p[i]) {
         c_w(i, d.first, p);
      }
   }

   int res = 0;
   for (int i = 0; i < N; i++) {
      auto maxi = max_element(p[i].begin(), p[i].end(), [](auto &l, auto &r) {
                     return l.second < r.second;
                  })->second;
      // cout << n - maxi << " ";
      res = max(res, N - maxi);
   }

   return res;
}

void generate_test_case(int min, int max) {
   // Generate random number of PCs (between 2 and 10)
   N = rand() % (max - 1) + min;

   // Generate cables connecting PCs
   cables.clear();
   for (int i = 0; i < N - 1; ++i) {
      int pc1 = i;
      int pc2 = rand() % (N - i - 1) + i + 1;  // Ensure PC2 is greater than PC1
      cables.push_back({pc1, pc2});
   }
}

void print() {
   // Print test case and answer
   cout << N << "\n";
   for (auto &cable : cables) {
      cout << cable.first << " " << cable.second << "\n";
   }
}

void print(int answer, int found) {
   // Print test case and answer
   print();
   cout << "Answer: " << answer << "\n";
   cout << "Found:" << found << "\n";
}

int main(int argc, char *argv[]) {
   // Seed random number generator with current time
   srand(time(NULL));

   if (argc != 3) {
      cout << "Usage: " << argv[0] << " <min_pcs> <max_pcs>"
           << "\n";
      return 1;
   }

   int min_pcs = atoi(argv[1]);
   int max_pcs = atoi(argv[2]);

   int a = 0, b = 0, i = 1;
   cout << 0;
   while (a == b && i < 1e5) {
      cout << "\r" << i++;
      generate_test_case(min_pcs, max_pcs);
      a = brute_force();
      b = solve();
   }

   print(a, b);

   return 0;
}
