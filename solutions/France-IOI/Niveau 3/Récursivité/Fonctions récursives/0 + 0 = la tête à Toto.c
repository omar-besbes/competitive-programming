#include <stdio.h>

void afficher(int Nombre) {
   if (Nombre == 0)
      printf("0");
   else {
      printf("(");
      afficher(Nombre - 1);
      printf(" + ");
      afficher(Nombre - 1);
      printf(")");
   }
}

int main() {
   int Nombre;
   scanf(" %d", &Nombre);
   printf("0 = ");
   afficher(Nombre);
}