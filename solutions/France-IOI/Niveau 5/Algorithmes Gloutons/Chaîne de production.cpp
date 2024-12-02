#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define all(x) x.begin(), x.end()

vector<int> solve(vector<int>& machines, vector<int>& jobs) {
   sort(all(jobs));
   int m = machines.size(), j = jobs.size();
   vector<int> cum(m, 0), ans(j, INT_MAX);
   for (int job = 0; job < j; job++) {
      pii mini = make_pair(INT_MAX, -1);
      for (int i = 0; i < m; i++)
         mini = min(mini, make_pair(cum[i] + machines[i], i));
      ans[job] = mini.first;
      cum[mini.second] = mini.first;
   }
   sort(all(ans));
   for (int job = 0; job < j; job++) ans[job] += jobs[j - job - 1];
   return ans;
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);

   int n;
   cin >> n;
   int A;
   cin >> A;
   vector<int> a(A);
   for (auto& i : a) cin >> i;
   int B;
   cin >> B;
   vector<int> b(B);
   for (auto& i : b) cin >> i;

   vector<int> input(n, 0);
   auto output1 = solve(a, input);
   auto ans1 = *max_element(all(output1));
   cout << ans1 << "\n";

   auto output2 = solve(b, output1);
   auto ans2 = *max_element(all(output2));
   cout << ans2 << "\n";
}