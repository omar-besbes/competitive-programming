#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
   int Longueur;
   scanf(" %d", &Longueur);
   char Expression[Longueur];
   scanf(" %[^\n]", Expression);

   int ouvrant = 0;
   int fermant = 0;
   for (int Caractere = 0; Caractere < Longueur; Caractere++) {
      if (Expression[Caractere] == '(')
         ouvrant++;
      else if (Expression[Caractere] == ')')
         fermant++;
      if (ouvrant < fermant) break;
   }

   if (ouvrant == fermant)
      printf("1");
   else
      printf("0");
}