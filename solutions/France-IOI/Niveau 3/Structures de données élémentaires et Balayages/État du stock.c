#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
   int Produits, Operations;
   scanf(" %d", &Produits);

   int Stock[Produits];
   for (int Produit = 0; Produit < Produits; Produit++)
      scanf(" %d", &Stock[Produit]);

   scanf(" %d", &Operations);
   int T_Demande, N_Demande;
   for (int Operation = 0; Operation < Operations; Operation++) {
      scanf(" %d %d", &T_Demande, &N_Demande);
      Stock[T_Demande - 1] += N_Demande;
   }

   for (int Produit = 0; Produit < Produits; Produit++)
      printf("%d ", Stock[Produit]);
}