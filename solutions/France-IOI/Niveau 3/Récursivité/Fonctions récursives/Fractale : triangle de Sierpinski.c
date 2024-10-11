#include <stdio.h>
#include <stdlib.h>

int main() {
   int Nombre;
   scanf(" %d", &Nombre);

   char Figure[Nombre][Nombre];
   for (int X = 0; X < Nombre; X++)
      for (int Y = 0; Y < Nombre; Y++) Figure[X][Y] = ' ';

   Figure[0][0] = '#';
   for (int dieze = 1; dieze < Nombre; dieze *= 2)
      for (int X = 0; X < dieze; X++)
         for (int Y = 0; Y < dieze; Y++) {
            Figure[X][Y + dieze] = Figure[X][Y];
            Figure[X + dieze][Y] = Figure[X][Y];
         }

   for (int X = 0; X < Nombre; X++) {
      for (int Y = 0; Y < Nombre; Y++) printf("%c", Figure[X][Y]);
      printf("\n");
   }
}