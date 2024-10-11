#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int main() {
   int NbBacs_initial, NbBacs_nouveau;
   scanf(" %d %d", &NbBacs_initial, &NbBacs_nouveau);

   int Stock_initial[NbBacs_initial];
   for (int Bac = 0; Bac < NbBacs_initial; Bac++)
      scanf(" %d", &Stock_initial[Bac]);

   int Stock_nouveau[NbBacs_nouveau];
   for (int Bac = 0; Bac < NbBacs_nouveau; Bac++)
      scanf(" %d", &Stock_nouveau[Bac]);

   int Nb = NbBacs_initial + NbBacs_nouveau;
   int Stock_final[Nb];
   for (int Bac = 0; Bac < NbBacs_initial; Bac++)
      Stock_final[Bac] = Stock_initial[Bac];

   int Nb_Actuel = NbBacs_initial - 1;
   for (int Bac1 = 0; Bac1 < NbBacs_nouveau; Bac1++) {
      bool verification = false;
      for (int Bac2 = 0; Bac2 <= Nb_Actuel; Bac2++)
         if (Stock_nouveau[Bac1] <= Stock_final[Bac2]) {
            for (int Bac3 = Nb - 1; Bac3 > Bac2; Bac3--)
               Stock_final[Bac3] = Stock_final[Bac3 - 1];
            Stock_final[Bac2] = Stock_nouveau[Bac1];
            printf("%d ", Bac2);
            Nb_Actuel++;
            verification = true;
            break;
         }
      if (Stock_nouveau[Bac1] > Stock_final[Nb_Actuel] && !verification) {
         Stock_final[++Nb_Actuel] = Stock_nouveau[Bac1];
         printf("%d ", Nb_Actuel);
      }
   }

   printf("\n");
   for (int Bac = 0; Bac < Nb; Bac++) printf("%d ", Stock_final[Bac]);
}