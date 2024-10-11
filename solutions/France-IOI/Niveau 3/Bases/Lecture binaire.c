#include <math.h>
#include <stdio.h>
#include <string.h>

int main() {
   char Nombre[26];
   scanf(" %s", Nombre);

   int L = strlen(Nombre);
   int resultat = 0;
   for (int chiffre = 0; chiffre < L; chiffre++)
      if (Nombre[chiffre] == '1') resultat += pow(2, L - chiffre - 1);

   printf("%d", resultat);
}