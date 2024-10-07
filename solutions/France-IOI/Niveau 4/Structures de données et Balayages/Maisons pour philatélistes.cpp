#include <algorithm>
#include <iostream>
using namespace std;

int main() {
   int nbMaisons;
   cin >> nbMaisons;
   long int Maison[nbMaisons];
   for (int M = 0; M < nbMaisons; M++) cin >> Maison[M];
   sort(Maison, Maison + nbMaisons);

   long int distance = 10000000000;
   for (int M = nbMaisons - 1; M > 0; M--) {
      long int D = Maison[M] - Maison[M - 1];
      if (distance > D) distance = D;
   }
   cout << distance;
}