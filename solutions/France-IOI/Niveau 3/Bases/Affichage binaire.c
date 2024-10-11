#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
   int Nombre;
   scanf(" %d", &Nombre);

   int puissance = 1;
   while (Nombre > pow(2, puissance)) puissance++;

   int binaire[puissance];
   int i = 0, P = puissance - 1;
   while (i < puissance) {
      binaire[i] = 0;
      i++;
   }

   i = puissance - 1;
   while (i >= 0) {
      if (Nombre >= pow(2, P)) {
         Nombre -= pow(2, P);
         binaire[i] = 1;
      }
      i--;
      P--;
   }
   
   i = puissance - 1;
   while (i >= 0) {
      printf("%d", binaire[i]);
      i--;
   }
}