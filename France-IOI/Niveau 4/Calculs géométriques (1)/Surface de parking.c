#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    /* Pour calculer le double de l'aire de ABC
    il suffit de trouver le produit vectoriel
    de deux des vecteurs AB AC BC
    En faisant le calcul de par exemple AB^AC,
    cela se rapporte à calculer leur déterminant */
    int X[3], Y[3];
    for (int i = 0; i < 3; i++)
        scanf("%d %d", X + i, Y + i);
    printf("%d", abs((X[1] - X[0]) * (Y[2] - Y[0]) - (Y[1] - Y[0]) * (X[2] - X[0])));

    return 0;
}