#include <iostream>
using namespace std;

int main() {
   int nbRequetes;
   cin >> nbRequetes;
   char requete;
   int hauteur[nbRequetes] = {0};
   int pos = 0;
   int actuel;
   int longueur = 0;
   for (int R = 0; R < nbRequetes; R++) {
      cin >> requete;
      if (requete == 'C') {
         cin >> actuel;
         while ((actuel >= hauteur[pos - 1]) & (pos > 0)) pos--;
         hauteur[pos] = actuel;
         longueur = ++pos;
      } else
         cout << longueur << endl;
   }
}