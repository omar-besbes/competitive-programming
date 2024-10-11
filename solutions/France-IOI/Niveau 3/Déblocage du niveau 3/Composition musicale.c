#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
   char musique[500];
   scanf(" %s", musique);
   int Nb_notes = strlen(musique);
   for (int x = Nb_notes; x >= 1; x--) {
      if ((musique[x] == musique[x - 1]) && (musique[x] != ' ')) {
         for (int y = x - 1; y <= Nb_notes - 2; y++) {
            musique[y] = musique[y + 2];
         }
         x = Nb_notes;
      }
   }
   printf("%s", musique);
   return 0;
}