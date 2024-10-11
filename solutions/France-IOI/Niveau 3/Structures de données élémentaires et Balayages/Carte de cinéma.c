#include <stdio.h>
#include <stdlib.h>

int main() {
   int N, *Q;
   scanf("%d", &N);

   double *P, Million = 1000001;
   P = (double *)calloc(N, sizeof(double));
   Q = (int *)calloc((int)Million, sizeof(int));
   for (int i = 0; i < N; i++) {
      scanf("%lf", P + i);
      if (Q[(int)P[i]] == 0)
         Q[(int)P[i]] = 1;
      else {
         printf("%.f", P[i]);
         return 0;
      }
   }

   printf("-1");

   return 0;
}