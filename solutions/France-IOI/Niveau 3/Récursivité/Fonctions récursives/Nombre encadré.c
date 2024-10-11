#include <stdio.h>
#include <stdlib.h>

void affichage(int Crochets, int Nombre) {
   if (Crochets >= 1) {
      printf("[");
      affichage(Crochets - 1, Nombre);
      printf("]");
   }
   if (Crochets == 0) printf("%d", Nombre);
}

int main() {
   int Nombre;
   scanf(" %d", &Nombre);
   int Crochets;
   scanf(" %d", &Crochets);
   affichage(Crochets, Nombre);
}