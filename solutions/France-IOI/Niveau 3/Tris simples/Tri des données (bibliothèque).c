#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compareEntier(const void* pEntier1, const void* pEntier2) {
   return (*(int*)(pEntier1) - *(int*)(pEntier2));
}

int main() {
   int NbBacs;
   scanf(" %d", &NbBacs);

   int Valeurs[NbBacs];
   for (int Bac = 0; Bac < NbBacs; Bac++) scanf(" %d", &Valeurs[Bac]);

   qsort(Valeurs, NbBacs, sizeof(int), compareEntier);

   for (int Bac = 0; Bac < NbBacs; Bac++) printf("%d ", Valeurs[Bac]);
}