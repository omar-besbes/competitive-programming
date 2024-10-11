#include <stdio.h>

int main() {
   int K, N;
   scanf(" %d %d", &K, &N);

   int Vitesse[N];
   int V_Act = 0;
   int V_Max = 0;
   for (int indice = 0; indice < N; indice++) {
      scanf(" %d", &Vitesse[indice]);
      V_Act += Vitesse[indice];
      if (indice >= K) V_Act -= Vitesse[indice - K];
      if (V_Act > V_Max) V_Max = V_Act;
   }

   printf("%d", V_Max);
}