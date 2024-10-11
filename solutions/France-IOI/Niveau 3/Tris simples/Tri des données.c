#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main() {
   int NbBacs;
   scanf(" %d", &NbBacs);

   int Pollution_Desordre[NbBacs];
   int Pollution_triees[NbBacs];
   for (int Bac = 0; Bac < NbBacs; Bac++) Pollution_triees[Bac] = 0;

   for (int Bac = 0; Bac < NbBacs; Bac++) {
      scanf(" %d", &Pollution_Desordre[Bac]);
      int Maximum = NbBacs - 1;
      while (1)
         if (Pollution_Desordre[Bac] > Pollution_triees[Maximum]) {
            for (int i = 0; i < Maximum; i++)
               Pollution_triees[i] = Pollution_triees[i + 1];
            Pollution_triees[Maximum] = Pollution_Desordre[Bac];
            break;
         } else if (Maximum > 0)
            Maximum--;
         else
            break;
   }

   for (int Bac = 0; Bac < NbBacs; Bac++) printf("%d ", Pollution_triees[Bac]);
}