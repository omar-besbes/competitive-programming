#include "bits/stdc++.h"
using namespace std;

int n, k, a;
typedef pair<long long, int> state;
vector<state> st;
vector<map<int, int>> adj;

int main() {
   ios::sync_with_stdio(false);

   cin >> n >> a >> k;
   k--;
   adj.resize(n, map<int, int>());
   st.resize(n);

   for (int i = 0; i < n; i++) st[i] = make_pair(LLONG_MAX, i);

   for (int i = 0; i < a; i++) {
      int a, b, d;
      cin >> a >> b >> d;
      adj[a - 1][b - 1] = d;
      adj[b - 1][a - 1] = d;
   }

   priority_queue<state, vector<state>, greater<state>> q;
   q.push(make_pair(0, k));
   while (!q.empty()) {
      long long d;
      int v;
      tie(d, v) = q.top();
      q.pop();

      if (st[v].first <= d) continue;
      st[v].first = d;

      for (auto entry : adj[v]) {
         int c, dc;
         tie(c, dc) = entry;
         q.push(make_pair(d + dc, c));
      }
   }

   sort(st.begin(), st.end(), [](const state a, const state b) {
      return a.first == b.first ? a.second < b.second : a.first < b.first;
   });
   while (st.back().first == LLONG_MAX) st.pop_back();

   for (auto i : st) cout << i.first << " " << i.second + 1 << "\n";
}