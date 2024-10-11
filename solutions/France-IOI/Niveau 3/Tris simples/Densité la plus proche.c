#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int V(int nombre) {
   if (nombre < 0)
      return -nombre;
   else
      return nombre;
}

int Comparer(const void* p1, const void* p2) {
   return *(int*)(p1) - *(int*)(p2);
}

int Valeur_Approchee(int L, int Densite[L], int Demande, int Moy1) {
   int Moy2 = Moy1 * 2, Moy3 = Moy1 * 3;
   if (Demande <= Densite[0])
      return Densite[0];
   else if (Demande >= Densite[L - 1])
      return Densite[L - 1];
   int resultat = 0;
   if (Demande < Densite[Moy1]) {
      int Bloc = 0;
      int distance = Densite[Bloc] - Demande;
      while (Bloc < Moy1) {
         Bloc++;
         if (V(Densite[Bloc] - Demande) < V(distance))
            distance = Densite[Bloc] - Demande;
         else if (V(Densite[Bloc] - Demande) == V(distance) &&
                  distance + Demande > Densite[Bloc])
            distance = Densite[Bloc] - Demande;
         else if (V(Densite[Bloc] - Demande) >= V(distance))
            break;
      }
      resultat = Demande + distance;
   } else if (Demande < Densite[Moy2]) {
      int Bloc = Moy1;
      int distance = Densite[Bloc] - Demande;
      while (Bloc < Moy2) {
         Bloc++;
         if (V(Densite[Bloc] - Demande) < V(distance))
            distance = Densite[Bloc] - Demande;
         else if (V(Densite[Bloc] - Demande) == V(distance) &&
                  distance + Demande > Densite[Bloc])
            distance = Densite[Bloc] - Demande;
         else if (V(Densite[Bloc] - Demande) >= V(distance))
            break;
      }
      resultat = Demande + distance;
   } else if (Demande < Densite[Moy3]) {
      int Bloc = Moy2;
      int distance = Densite[Bloc] - Demande;
      while (Bloc < Moy3) {
         Bloc++;
         if (V(Densite[Bloc] - Demande) < V(distance))
            distance = Densite[Bloc] - Demande;
         else if (V(Densite[Bloc] - Demande) == V(distance) &&
                  distance + Demande > Densite[Bloc])
            distance = Densite[Bloc] - Demande;
         else if (V(Densite[Bloc] - Demande) >= V(distance))
            break;
      }
      resultat = Demande + distance;
   } else if (Demande < Densite[L - 1]) {
      int Bloc = Moy3;
      int distance = Densite[Bloc] - Demande;
      while (Bloc < L) {
         Bloc++;
         if (V(Densite[Bloc] - Demande) < V(distance))
            distance = Densite[Bloc] - Demande;
         else if (V(Densite[Bloc] - Demande) == V(distance) &&
                  distance + Demande > Densite[Bloc])
            distance = Densite[Bloc] - Demande;
         else if (V(Densite[Bloc] - Demande) >= V(distance))
            break;
      }
      resultat = Demande + distance;
   }
   return resultat;
}

int main() {
   int Questions, Blocs;
   scanf(" %d", &Blocs);

   int Densite[Blocs];
   for (int Bloc = 0; Bloc < Blocs; Bloc++) scanf(" %d", &Densite[Bloc]);

   qsort(Densite, Blocs, 4, Comparer);

   scanf(" %d", &Questions);
   int Demande;
   int Question = 0;
   int Moy = Blocs / 4;
   while (Question < Questions) {
      scanf(" %d", &Demande);
      printf("%d\n", Valeur_Approchee(Blocs, Densite, Demande, Moy));
      Question++;
   }
}