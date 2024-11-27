#include <bits/stdc++.h>
using namespace std;
#define input "input.in"
#define output "testcase.txt"

const int maxi = 10;

void solve() {
   int n = (rand() % maxi) + 1, m = (rand() % maxi) + 1;
   int x = (rand() % n) + 1, y = (rand() % m) + 1;
   cout << n << " " << m << " " << x << " " << y << "\n";
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);

   if (fopen(input, "r")) freopen(input, "r", stdin);
   if (fopen(output, "r")) freopen(output, "w+", stdout);

   srand(time(0));
   int t = rand() % 1000;
   cout << t << "\n";
   while (t--) solve();
}