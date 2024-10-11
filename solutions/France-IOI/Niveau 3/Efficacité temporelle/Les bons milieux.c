#include <stdio.h>
#include <stdlib.h>

void Verif(int nbPoints, int **Point, int **Milieu, int i, int j,
           int *nbMilieux) {
   if ((Point[i][0] + Point[j][0]) % 2 != 0 ||
       (Point[i][1] + Point[j][1]) % 2 != 0)
      return;
   int X = (Point[i][0] + Point[j][0]) / 2;
   int Y = (Point[i][1] + Point[j][1]) / 2;
   for (int a = 0; a < nbPoints; a++)
      if (X - Point[a][0] == 0 && Y - Point[a][1] == 0) {
         int b = 0, Test = 1;
         while (b < *nbMilieux) {
            if (X == Milieu[b][0] && Y == Milieu[b][1]) {
               Test = 0;
               break;
            }
            b++;
         }
         if (Test == 1) {
            Milieu[*nbMilieux][0] = X;
            Milieu[*nbMilieux][1] = Y;
            (*nbMilieux)++;
         }
         break;
      }
}

int main() {
   int nbPoints, **Point, **Milieu, nbMilieux = 0;
   scanf("%d", &nbPoints);
   Point = (int **)malloc(nbPoints * sizeof(int *));
   Milieu = (int **)malloc(nbPoints * sizeof(int *));
   for (int i = 0; i < nbPoints; i++) {
      Point[i] = (int *)malloc(2 * sizeof(int));
      Milieu[i] = (int *)malloc(2 * sizeof(int));
      scanf("%d %d", Point[i], Point[i] + 1);
   }

   for (int i = 0; i < nbPoints; i++) {
      int j = i + 1;
      while (j < nbPoints) {
         Verif(nbPoints, Point, Milieu, i, j, &nbMilieux);
         j++;
      }
   }

   printf("%d", nbMilieux);
   return 0;
}