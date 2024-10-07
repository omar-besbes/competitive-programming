#include <iostream>
#include <string>
using namespace std;

void positions(int Recipient[], int objet) {
   if (Recipient[objet - 1] == 0)
      cout << objet << " ";
   else {
      positions(Recipient, Recipient[objet - 1]);
      cout << objet << " ";
   }
}

int main() {
   int nbObjets;
   cin >> nbObjets;
   int Recipient[nbObjets] = {0};
   for (int o = 0; o < nbObjets; o++) cin >> Recipient[o];
   int nbRecherche;
   cin >> nbRecherche;
   int OR = 0;
   for (int r = 0; r < nbRecherche; r++) {
      cin >> OR;
      positions(Recipient, OR);
      cout << "" << endl;
   }
}