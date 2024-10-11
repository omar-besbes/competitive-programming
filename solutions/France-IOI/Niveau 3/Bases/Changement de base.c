#include <math.h>
#include <stdio.h>
#include <string.h>

int main() {
   int B_Arrivee, B_Depart, Nb_Depart;
   scanf(" %d %d %d", &B_Depart, &B_Arrivee, &Nb_Depart);

   int Nombre = 0;
   for (int Chiffre = Nb_Depart - 1; Chiffre >= 0; Chiffre--) {
      int Entier;
      scanf(" %d", &Entier);
      Nombre += pow(B_Depart, Chiffre) * Entier;
   }

   int Nb_Arivee = 0;
   int N = Nombre;
   if (N == 0)
      Nb_Arivee = 1;
   else
      while (N != 0) {
         N /= B_Arrivee;
         Nb_Arivee++;
      }

   int resultat[Nb_Arivee];
   for (int Chiffre = Nb_Arivee - 1; Chiffre >= 0; Chiffre--) {
      resultat[Chiffre] = Nombre % B_Arrivee;
      Nombre /= B_Arrivee;
   }

   for (int Chiffre = 0; Chiffre < Nb_Arivee; Chiffre++)
      printf("%d ", resultat[Chiffre]);
}