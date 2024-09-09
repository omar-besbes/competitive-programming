#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

int compareEntier(const void *pEntier1, const void *pEntier2)
{
    return (*(int *)(pEntier1) - *(int *)(pEntier2));
}

int main()
{
    int Na;
    scanf(" %d", &Na);
    int Dechets_a[Na];
    for (int Bac = 0; Bac < Na; Bac++)
        scanf(" %d", &Dechets_a[Bac]);

    int Nb;
    scanf(" %d", &Nb);
    int Dechets_b[Nb];
    for (int Bac = 0; Bac < Nb; Bac++)
        scanf(" %d", &Dechets_b[Bac]);

    int N = Na + Nb;
    int Dechets[N];
    for (int Bac = 0; Bac < Na; Bac++)
        Dechets[Bac] = Dechets_a[Bac];
    for (int Bac = Na; Bac < N; Bac++)
        Dechets[Bac] = Dechets_b[Bac - Na];
    qsort(Dechets, N, 4, compareEntier);

    for (int Bac = 0; Bac < N; Bac++)
        printf("%d ", Dechets[Bac]);
}