#include "bits/stdc++.h"
using namespace std;

int main() {
   int n;
   cin >> n;

   cout << n / 2 << " " << (n - 1) / 2 << "\n";

   for (int i = 0; i < n - 1 - i; i++) cout << i + 1 << " " << n - i << "\n";

   for (int i = 0; i < n - 2 - i; i++)
      cout << i + 1 << " " << n - 1 - i << "\n";
}