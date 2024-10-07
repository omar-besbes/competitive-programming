#include "bits/stdc++.h"
using namespace std;

int main() {
   int n;
   cin >> n;
   for (int i = 0; i < (1 << n); i++)
      cout << (bitset<16>(i ^ (i >> 1))).to_string().substr(16 - n) << "\n";
}