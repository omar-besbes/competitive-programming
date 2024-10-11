#include <stdio.h>
#include <stdlib.h>

int main() {
   int Nb;
   scanf(" %d", &Nb);
   int Nb_L;
   Nb_L = Nb * 2 - 1;
   char lettre = 97;

   for (int y = 0; y < Nb; y++) {
      int x;
      lettre = 97;
      for (x = 0; x <= y; x++) {
         if (x == y) {
            lettre = lettre + x;
            while (x < Nb_L - y) {
               printf("%c", lettre);
               x++;
            }
         } else
            printf("%c", lettre + x);
      }
      lettre = 97;
      x = y - 1;
      while (97 + x >= 97) {
         lettre = 97 + x;
         printf("%c", lettre);
         x--;
      }
      printf("\n");
   }

   for (int y = Nb - 2; y >= 0; y--) {
      int x;
      lettre = 97;
      for (x = 0; x <= y; x++) {
         if (x == y) {
            lettre = lettre + x;
            while (x < Nb_L - y) {
               printf("%c", lettre);
               x++;
            }
         } else
            printf("%c", lettre + x);
      }
      lettre = 97;
      x = y - 1;
      while (97 + x >= 97) {
         lettre = 97 + x;
         printf("%c", lettre);
         x--;
      }
      printf("\n");
   }

   return 0;
}