#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int main() {
   int NbBacs_Stock, NbBacs_Camion;
   scanf(" %d %d", &NbBacs_Stock, &NbBacs_Camion);

   int Bacs_Desordre[NbBacs_Stock];
   int Bacs_Tries[NbBacs_Camion];
   for (int Bac = 0; Bac < NbBacs_Stock; Bac++) Bacs_Tries[Bac] = 0;

   for (int Bac1 = 0; Bac1 < NbBacs_Stock; Bac1++) {
      scanf(" %d", &Bacs_Desordre[Bac1]);
      int Pollution_Bac = Bacs_Desordre[Bac1];
      for (int Bac2 = NbBacs_Camion - 1; Bac2 >= 0; Bac2--)
         if (Pollution_Bac > Bacs_Tries[Bac2] && Bac2 > 0) {
            for (int Bac3 = 0; Bac3 < Bac2; Bac3++)
               Bacs_Tries[Bac3] = Bacs_Tries[Bac3 + 1];
            Bacs_Tries[Bac2] = Pollution_Bac;
            break;
         } else if (Pollution_Bac > Bacs_Tries[0])
            Bacs_Tries[0] = Pollution_Bac;
   }

   for (int Bac = NbBacs_Camion - 1; Bac >= 0; Bac--)
      printf("%d ", Bacs_Tries[Bac]);
}