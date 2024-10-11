#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int conversion(char Nombre[]) {
   int L = strlen(Nombre);
   int resultat = 0;
   for (int caractere = 0; caractere < L; caractere++) {
      if (isupper(Nombre[caractere]))
         Nombre[caractere] -= 55;
      else
         Nombre[caractere] -= 48;
      resultat += ((int)Nombre[caractere]) * (pow(16, L - caractere - 1));
   }
   return resultat;
}

int main() {
   char Nombre[2];
   scanf(" %s", Nombre);

   int pre_resultat = 0;
   int N = conversion(Nombre);
   char hexadecimal[4];
   for (int lire = 0; lire < N; lire++) {
      scanf(" %s", hexadecimal);
      pre_resultat += conversion(hexadecimal);
   }
   pre_resultat /= N;

   char resultat[4];
   int caractere = 0;
   for (caractere = 0; caractere < 4; caractere++) {
      if ((pre_resultat % 16) / 10 >= 1) {
         int Entier = (pre_resultat % 16) % 10 + 65;
         resultat[caractere] = Entier;
      } else
         resultat[caractere] = (pre_resultat % 16);
      pre_resultat /= 16;
      if (pre_resultat == 0) break;
   }

   for (int i = caractere; i >= 0; i--)
      if ((int)resultat[i] < 10)
         printf("%d", (int)resultat[i]);
      else
         printf("%c", resultat[i]);
}