#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int CompareEntier(const void* pEntier1, const void* pEntier2) {
   return (*(int*)(pEntier1) - *(int*)(pEntier2));
}

int main() {
   int Operations;
   scanf(" %d", &Operations);

   int Nb_Produits = 0;
   int Produit[1000];
   for (int Operation = 0; Operation < Operations; Operation++) {
      int N, Date;
      scanf(" %d %d", &N, &Date);
      if (N > 0) {
         int Nb = Nb_Produits;
         Nb_Produits += N;
         while (N > 0) {
            Nb += N;
            Produit[Nb - 1] = Date;
            Nb -= N;
            N--;
         }
      } else
         Nb_Produits += N;
   }

   qsort(Produit, Nb_Produits, sizeof(int), CompareEntier);
   int N = 0;
   while (Produit[N] == 0) N++;
   printf("%d", Produit[N]);
}