#include <iostream>
using namespace std;

int main() {
   int nbLignes, nbColonnes, espace;
   cin >> nbLignes >> nbColonnes >> espace;

   int Grille[nbLignes][nbColonnes];
   for (int ligne = 0; ligne < nbLignes; ligne++)
      for (int colonne = 0; colonne < nbColonnes; colonne++)
         cin >> Grille[ligne][colonne];

   int ligne = 0, colonne = 0;
   for (int mouvement = 1; mouvement < nbColonnes * nbLignes; mouvement++) {
      if (mouvement % (espace + 1) == 0)
         cout << ligne << " " << colonne << endl;
      if (ligne == nbLignes - 1 && colonne == nbColonnes - 1) break;
      if (Grille[ligne + 1][colonne] == 0 && ligne != nbLignes - 1) {
         Grille[ligne][colonne] = 1;
         ligne++;
      } else if (Grille[ligne - 1][colonne] == 0 && ligne != 0) {
         Grille[ligne][colonne] = 1;
         ligne--;
      } else if (Grille[ligne][colonne + 1] == 0 && colonne != nbColonnes - 1) {
         Grille[ligne][colonne] = 1;
         colonne++;
      } else if (Grille[ligne][colonne - 1] == 0 && colonne != 0) {
         Grille[ligne][colonne] = 1;
         colonne--;
      }
   }
}