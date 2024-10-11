#include <stdio.h>
#include <stdlib.h>

void afficher(int N, int M) {
   if (N <= M) {
      printf("%d ", N);
      afficher(N + 1, M);
   }
}

int main() {
   int Nombre1, Nombre2;
   scanf(" %d %d", &Nombre1, &Nombre2);
   afficher(Nombre1, Nombre2);
}