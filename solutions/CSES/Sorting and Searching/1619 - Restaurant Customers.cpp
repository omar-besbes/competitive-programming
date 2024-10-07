#include <bits/stdc++.h>
using namespace std;

int main() {
   int n;
   cin >> n;
   vector<int> arrival(n), ending(n);
   for (int i = 0; i < n; i++) cin >> arrival[i] >> ending[i];

   sort(arrival.begin(), arrival.end());
   sort(ending.begin(), ending.end());

   int curr = 0, maxi = 0;
   int i = 0, j = 0;
   for (; j < n && i < n;) {
      if (arrival[i] > ending[j]) curr--, j++;
      if (arrival[i] < ending[j]) curr++, i++;
      maxi = max(maxi, curr);
   }

   cout << maxi;
}