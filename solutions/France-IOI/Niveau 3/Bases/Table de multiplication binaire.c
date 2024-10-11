#include <math.h>
#include <stdio.h>
#include <string.h>

void conversion(int Nombre, int Base) {
   int NbChiffres = 0;
   int N = Nombre;
   if (N == 0)
      NbChiffres = 1;
   else
      while (N != 0) {
         N /= Base;
         NbChiffres++;
      }

   int resultat[NbChiffres];
   for (int Chiffre = NbChiffres - 1; Chiffre >= 0; Chiffre--) {
      resultat[Chiffre] = Nombre % Base;
      Nombre /= Base;
   }

   for (int Chiffre = 0; Chiffre < NbChiffres; Chiffre++)
      printf("%d", resultat[Chiffre]);
   printf("\t");
}

int main() {
   int Cote;
   scanf(" %d", &Cote);

   for (int x = 0; x < Cote; x++) {
      for (int y = 0; y < Cote; y++) conversion((x + 1) * (y + 1), 2);
      printf("\n");
   }
}