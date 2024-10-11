#include <stdio.h>
#include <stdlib.h>

float Moy(float x, float y) { return (x + y) / 2; }

int propriete(float x, float y, float Diff_max) {
   float z = y - x;
   if (z < 0) z = -z;
   if (z > Diff_max)
      return 0;
   else
      return 1;
}

int main() {
   float Diff_max;
   int Nb_mesures;
   scanf(" %d", &Nb_mesures);
   scanf(" %f", &Diff_max);

   int Num_mesure;
   int Total_proprietes = 0;
   int passage = 1;

   float mesure1[Nb_mesures];
   for (Num_mesure = 0; Num_mesure < Nb_mesures; Num_mesure++)
      scanf(" %f", &mesure1[Num_mesure]);

   float mesure2[Nb_mesures];

   for (Num_mesure = 0; Num_mesure <= Nb_mesures - 2; Num_mesure++)
      if (propriete(mesure1[Num_mesure], mesure1[Num_mesure + 1], Diff_max) ==
          1)
         Total_proprietes++;

   if (Total_proprietes == Nb_mesures - 1)
      printf("0");
   else {
      while (passage <= 5000) {
         for (Num_mesure = 0; Num_mesure < Nb_mesures; Num_mesure++) {
            if (Num_mesure == 0 || Num_mesure == Nb_mesures - 1)
               mesure2[Num_mesure] = mesure1[Num_mesure];
            else
               mesure2[Num_mesure] =
                   Moy(mesure1[Num_mesure - 1], mesure1[Num_mesure + 1]);
         }
         for (Num_mesure = 0; Num_mesure <= Nb_mesures - 2; Num_mesure++)
            if (propriete(mesure2[Num_mesure], mesure2[Num_mesure + 1],
                          Diff_max) == 1)
               Total_proprietes++;
         if (Total_proprietes == Nb_mesures - 1)
            break;
         else {
            for (Num_mesure = 0; Num_mesure < Nb_mesures; Num_mesure++)
               mesure1[Num_mesure] = mesure2[Num_mesure];
            Total_proprietes = 0;
            passage++;
         }
      }
      if (passage == 2)
         printf("1");
      else
         printf("%d", passage);
   }
}