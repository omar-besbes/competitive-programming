#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool estpalindrome(int debut, int fin, char ligne[]) {
   while (debut < fin) {
      if (ligne[debut] != ligne[fin]) return false;
      debut++;
      fin--;
   }
   return true;
}

int main() {
   char ligne[2001];
   scanf(" %s", ligne);
   int L = strlen(ligne);

   int Lpalindorme = L;
   int resultat = 1;
   while (Lpalindorme > 1) {
      int debut = 0;
      int fin = Lpalindorme - 1 + debut;
      while (fin < L) {
         if (estpalindrome(debut, fin, ligne)) {
            resultat = Lpalindorme;
            break;
         } else {
            debut++;
            fin++;
         }
      }
      if (resultat != 1) break;
      Lpalindorme--;
   }

   printf("%d", resultat);
}