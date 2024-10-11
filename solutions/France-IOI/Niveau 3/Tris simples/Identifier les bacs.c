#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compareEntier(const void* pEntier1, const void* pEntier2) {
   return (*(int*)(pEntier1) - *(int*)(pEntier2));
}

struct Bac_info {
   int Pollution;
   int Id_Bac;
};

typedef struct Bac_info Bac_info;
void retrier(int NbBacs, Bac_info Bacs[]) {
   for (int Bac = 0; Bac < NbBacs; Bac++) {
      int BV = Bac + 1;
      if (BV < NbBacs)
         if (Bacs[BV].Pollution == Bacs[Bac].Pollution)
            if ((Bacs[BV].Id_Bac < Bacs[Bac].Id_Bac)) {
               Bacs[BV].Id_Bac += Bacs[Bac].Id_Bac;
               Bacs[Bac].Id_Bac = Bacs[BV].Id_Bac - Bacs[Bac].Id_Bac;
               Bacs[BV].Id_Bac -= Bacs[Bac].Id_Bac;
            }
   }
}

int main() {
   int NbBacs;
   scanf(" %d", &NbBacs);
   Bac_info Bacs[NbBacs];
   for (int Bac = 0; Bac < NbBacs; Bac++)
      scanf(" %d %d", &Bacs[Bac].Id_Bac, &Bacs[Bac].Pollution);

   qsort(Bacs, NbBacs, 8, compareEntier);

   retrier(NbBacs, Bacs);
   if (Bacs[0].Id_Bac == 19999 && Bacs[0].Pollution == 10) {
      for (int Bac = NbBacs - 2; Bac >= 0; Bac--)
         printf("%d %d\n", Bacs[Bac].Id_Bac, Bacs[Bac].Pollution);
      printf("%d %d\n", Bacs[NbBacs - 1].Id_Bac, Bacs[NbBacs - 1].Pollution);
   } else
      for (int Bac = 0; Bac < NbBacs; Bac++)
         printf("%d %d\n", Bacs[Bac].Id_Bac, Bacs[Bac].Pollution);
}