#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int CompareString(const void* pString1, const void* pString2) {
   return strcmp((const char*)(pString1), (const char*)(pString2));
}

int main() {
   int NbElements;
   scanf(" %d", &NbElements);

   char mot[NbElements][101];
   for (int Element = 0; Element < NbElements; Element++)
      scanf(" %s", mot[Element]);

   qsort(mot, NbElements, 101 * sizeof(char), CompareString);

   for (int Element = 0; Element < NbElements; Element++)
      printf("%s\n", mot[Element]);
}