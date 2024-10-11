#include <stdio.h>
#include <stdlib.h>

int main() {
   int L, C, nbArbustes = 0;
   scanf("%d %d", &L, &C);
   char X;
   scanf("\n");
   for (int i = 0; i < L; i++) {
      for (int j = 0; j < C; j++) {
         scanf("%c", &X);
         if (X == '#') nbArbustes++;
      }
      scanf("\n");
   }
   printf("%d", nbArbustes);
   return 0;
}