#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int NbChangements(int Nb, int nombre[Nb]) {
   int resultat = 0;
   int position = 0;
   for (int chiffre = position + 1; chiffre <= Nb; chiffre++)
      for (position = 0; position < Nb; position++)
         if (nombre[position] == chiffre) {
            int PM = position;
            while (PM >= chiffre) {
               int permuter = nombre[PM];
               nombre[PM] = nombre[PM - 1];
               nombre[PM - 1] = permuter;
               PM--;
               resultat++;
            }
         }
   return resultat;
}

int main() {
   int NbAutomobiles;
   scanf(" %d", &NbAutomobiles);

   int automobile[NbAutomobiles];
   for (int position = 0; position < NbAutomobiles; position++)
      scanf(" %d", &automobile[position]);

   int copie[NbAutomobiles];
   for (int position = 0; position < NbAutomobiles; position++)
      copie[position] = automobile[position];
   int N_C = NbChangements(NbAutomobiles, copie);
   printf("%d\n", N_C);

   int position = 0;
   for (int chiffre = position + 1; chiffre <= NbAutomobiles; chiffre++)
      for (position = 0; position < NbAutomobiles; position++)
         if (automobile[position] == chiffre) {
            int PM = position;
            while (PM >= chiffre) {
               printf("%d %d\n", automobile[PM - 1], automobile[PM]);
               int permuter = automobile[PM];
               automobile[PM] = automobile[PM - 1];
               automobile[PM - 1] = permuter;
               PM--;
            }
         }
}