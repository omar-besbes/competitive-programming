#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int Comparer(const void *p1, const void *p2)
{
    return *(int *)(p1) - *(int *)(p2);
}

int main()
{
    int N;
    scanf(" %d", &N);

    int Entiers[N];
    for (int i = 0; i < N; i++)
        scanf(" %d", &Entiers[i]);
    qsort(Entiers, N, 4, Comparer);

    int debut = 0, fin = N - 1;
    int resultat = 0;
    while (debut < fin && Entiers[debut] <= 0 && Entiers[fin] >= 0)
        if (Entiers[debut] == Entiers[debut - 1])
            debut++;
        else if (Entiers[fin] == Entiers[fin + 1])
            fin--;
        else if (-Entiers[debut] == Entiers[fin])
        {
            resultat++;
            debut++;
            fin--;
        }
        else if (-Entiers[debut] > Entiers[fin])
            debut++;
        else if (-Entiers[debut] < Entiers[fin])
            fin--;

    printf("%d", resultat);
}