#include <iostream>
using namespace std;

int main() {
   int nbPots, Quantite;
   cin >> nbPots >> Quantite;
   int Pots[nbPots];
   for (int pot = 0; pot < nbPots; pot++) cin >> Pots[pot];

   int debut = 0;
   int fin = nbPots - 1;
   while (debut <= fin) {
      while (Pots[fin] + Pots[debut] > Quantite) fin--;
      while (Pots[fin] + Pots[debut] < Quantite) debut++;
      if (Pots[fin] + Pots[debut] == Quantite) {
         cout << "OUI" << endl;
         return 0;
      }
   }
   cout << "NON" << endl;
}