#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
   int NbJours, NbLivres;
   scanf(" %d %d", &NbLivres, &NbJours);
   int NbClients;
   int jour, livre, client;
   int duree;
   int livre_dispo[NbLivres];
   for (livre = 0; livre < NbLivres; livre++) livre_dispo[livre] = 0;
   for (jour = 1; jour <= NbJours; jour++) {
      scanf(" %d", &NbClients);
      for (client = 1; client <= NbClients; client++) {
         scanf(" %d %d", &livre, &duree);
         if (livre_dispo[livre] == 0) {
            livre_dispo[livre] = duree;
            printf("1\n");
         } else
            printf("0\n");
      }
      for (livre = 0; livre < NbLivres; livre++)
         if (livre_dispo[livre] > 0) livre_dispo[livre]--;
   }
   return 0;
}