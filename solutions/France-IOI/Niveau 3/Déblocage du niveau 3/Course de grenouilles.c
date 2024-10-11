#include <stdbool.h>
#include <stdio.h>

bool verification;

int Max(int Tableau[], int Valeur1, int Valeur2) {
   if (Valeur2 < 0) return Valeur1;
   if (Valeur1 < 0) return Valeur2;
   if (Tableau[Valeur1] > Tableau[Valeur2])
      return Valeur1;
   else if (Tableau[Valeur1] == Tableau[Valeur2])
      if (Valeur1 < Valeur2)
         return Valeur1;
      else
         return Valeur2;
   else
      return Valeur2;
}

int Strict_Max(int Tableau[], int Valeur1, int Valeur2) {
   if (Tableau[Valeur1] > Tableau[Valeur2])
      return Valeur1;
   else if (Tableau[Valeur1] == Tableau[Valeur2])
      if (verification)
         return -10;
      else {
         verification = true;
         return Valeur1;
      }
   else
      return Valeur2;
}

int main() {
   // T pour Tour(s) et G pour Grenouille(s)
   int Nb_T, Nb_G;
   scanf(" %d %d", &Nb_G, &Nb_T);

   int Gr[Nb_G];
   for (int G = 0; G < Nb_G; G++) Gr[G] = 0;

   int GG[Nb_T];
   for (int T = 0; T < Nb_T; T++) GG[T] = 0;

   int Frequence[Nb_G];
   for (int G = 0; G < Nb_G; G++) Frequence[G] = 0;

   int Gagnante = -10;
   for (int T = 1; T <= Nb_T; T++) {
      int G, saut;
      scanf(" %d %d", &G, &saut);
      if (T != Nb_T) {
         Gr[G - 1] += saut;
         for (G = 0; G < Nb_G; G++) GG[T] = Max(Gr, G, GG[T]);
         verification = false;
         for (G = 0; G < Nb_G; G++) {
            GG[T] = Strict_Max(Gr, G, GG[T]);
            if (GG[T] < 0) break;
         }
         if (GG[T] >= 0) Frequence[GG[T]]++;
         if (T == Nb_T - 1) {
            for (G = 0; G < Nb_G; G++) Gagnante = Max(Frequence, G, Gagnante);
         }
      }
   }

   if (Gagnante + 1 == -9)
      printf("1");
   else
      printf("%d", Gagnante + 1);
}