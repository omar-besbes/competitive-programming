#include <math.h>
#include <stdio.h>
#include <string.h>

int main() {
   int Nombre, Base;
   scanf(" %d %d", &Nombre, &Base);

   int NbChiffres = 0;
   int N = Nombre;
   if (N == 0)
      NbChiffres = 1;
   else
      while (N != 0) {
         N /= Base;
         NbChiffres++;
      }
   printf("%d\n", NbChiffres);

   int resultat[NbChiffres];
   for (int Chiffre = NbChiffres - 1; Chiffre >= 0; Chiffre--) {
      resultat[Chiffre] = Nombre % Base;
      Nombre /= Base;
   }

   for (int Chiffre = 0; Chiffre < NbChiffres; Chiffre++)
      printf("%d ", resultat[Chiffre]);
}