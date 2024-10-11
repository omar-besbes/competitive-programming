#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void afficher(int L, char ligne[L]) {
   L--;
   if (L >= 0) {
      printf("%c", ligne[L]);
      afficher(L, ligne);
   }
}

int main() {
   char ligne[201];
   scanf(" %[^\n]", ligne);
   int L = strlen(ligne);
   afficher(L, ligne);
}