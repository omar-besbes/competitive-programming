#include <stdio.h>
#include <stdlib.h>

typedef struct Noeud {
   int valeur;
   struct Noeud *suivant, *precedent;
} Cell;
typedef Cell *Pile;

Pile P[3] = {NULL, NULL, NULL};
int tete(Pile *P) { return (*P)->valeur; }

Pile queue(Pile *P) {
   Pile AvantDernier = *P, Dernier = (*P)->suivant;
   while (Dernier) {
      AvantDernier = Dernier;
      Dernier = Dernier->suivant;
   }
   return AvantDernier;
}

Pile chercher(Pile *P, int x) {
   Pile Dernier = *P, AvantDernier = *P;
   while (Dernier && tete(&Dernier) < x) {
      AvantDernier = Dernier;
      Dernier = Dernier->suivant;
   }
   return AvantDernier;
}

Pile trouver(int x) {
   Pile L;
   for (int i = 0; i < 3; i++) {
      L = P[i];
      while (L && L->valeur != x) L = L->suivant;
      if (L) return L;
   }
   return L;
}

void depiler(Pile *P) {
   if (*P) {
      Pile Precedent = *P;
      (*P) = (*P)->suivant;
      free(Precedent);
      if (*P) (*P)->precedent = NULL;
   }
}

void empiler(Pile *P, int x) {
   Pile Nouveau = (Pile)malloc(sizeof(Cell));
   Nouveau->valeur = x;
   Nouveau->suivant = *P;
   Nouveau->precedent = NULL;
   if (*P != NULL) (*P)->precedent = Nouveau;
   *P = Nouveau;
}

int deplacer(int Depart, int Destination, Pile *D) {
   int x = (*D)->valeur;
   if (*(P + Destination) != NULL && tete(P + Destination) < x) return 0;
   if (*(P + Depart) != NULL && tete(P + Depart) == x) {
      depiler(P + Depart);
      D = P + Destination;
      empiler(P + Destination, x);
      printf("%d -> %d\n", Depart + 1, Destination + 1);
      return 1;
   }
   return 0;
}

void soulever(int Depart, int Destination, Pile D) {
   if (*(P + Depart) != NULL && D->valeur != tete(P + Depart))
      soulever(Depart, 3 - Destination - Depart, D->precedent);
   int x = deplacer(Depart, Destination, &D);
   if (!x) {
      soulever(Destination, 3 - Destination - Depart,
               chercher(P + Destination, D->valeur));
      deplacer(Depart, Destination, &D);
   }
   Pile X = trouver(D->valeur - 1);
   if (X) soulever(3 - Destination - Depart, Destination, X);
}

int main() {
   int N;
   scanf("%d", &N);
   for (int i = 0; i < N; i++) empiler(P, N - i);
   soulever(0, 2, queue(P));
   return 0;
}