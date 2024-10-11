#include <math.h>
#include <stdio.h>
#include <string.h>

int main() {
   int Base, NbChiffres;
   scanf(" %d %d", &Base, &NbChiffres);

   int resultat = 0;
   int Entier;
   for (int Chiffre = NbChiffres - 1; Chiffre >= 0; Chiffre--) {
      scanf(" %d", &Entier);
      resultat += pow(Base, Chiffre) * Entier;
   }

   printf("%d", resultat);
}