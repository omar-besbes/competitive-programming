#include "bits/stdc++.h"
using namespace std;

int main() {
   string s;
   cin >> s;
   map<char, int> m;
   for (auto i : s) m[i]++;

   int nbodd = 0;
   char odd;
   for (auto [k, v] : m)
      if (v & 1) nbodd++, odd = k;

   if (nbodd > 1)
      cout << "NO SOLUTION\n";
   else {
      for (auto i = m.begin(); i != m.end(); i++) {
         auto [k, v] = *i;
         if (!(v & 1)) {
            for (int j = 0; j < v / 2; j++) cout << k;
         }
      }

      if (nbodd > 0) {
         for (int i = 0; i < m[odd]; i++) cout << odd;
      }

      for (auto i = m.rbegin(); i != m.rend(); i++) {
         auto [k, v] = *i;
         if (!(v & 1)) {
            for (int j = 0; j < v / 2; j++) cout << k;
         }
      }

      cout << "\n";
   }
}