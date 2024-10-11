#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
   int N;
   scanf(" %d", &N);

   int pusisance = 0;
   while (N > 1) {
      N /= 2;
      pusisance++;
   }

   int resultat = (pusisance == 0) ? 1 : pow(2, (double)pusisance);
   printf("%d", resultat);
}