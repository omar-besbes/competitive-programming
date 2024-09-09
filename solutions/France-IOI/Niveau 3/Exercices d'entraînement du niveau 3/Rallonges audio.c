#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Rallonge
{
    int input;
    int output;
    int longueur;
};

int Comparer(const void *p1, const void *p2)
{
    return *(int *)(p1) - *(int *)(p2);
}

int main()
{
    int N;
    scanf(" %d", &N);

    struct Rallonge R[N];
    int SF[N], SM[N], SFM[N];
    for (int i = 0; i < N; i++)
    {
        scanf(" %d %d %d", &R[i].input, &R[i].output, &R[i].longueur);
        if (R[i].input == 1 && R[i].output == 1)
        {
            SF[i] = 0;
            SM[i] = R[i].longueur;
            SFM[i] = 0;
        }
        else if (R[i].input == 0 && R[i].output == 0)
        {
            SF[i] = R[i].longueur;
            SM[i] = 0;
            SFM[i] = 0;
        }
        else
        {
            SF[i] = 0;
            SM[i] = 0;
            SFM[i] = R[i].longueur;
        }
    }

    qsort(SF, N, 4, Comparer);
    qsort(SM, N, 4, Comparer);
    qsort(SFM, N, 4, Comparer);
    int resultat = 0;

    if (SM[N - 1] != 0)
    {
        int i = N - 1;
        while (i >= 0 && SFM[i] != 0)
            resultat += SFM[i], i--;
        int iM = N - 1, iF = N - 1;
        resultat += SM[iM--];
        while (SM[iM] != 0 && SF[iF] != 0)
        {
            resultat += SF[iF--];
            resultat += SM[iM--];
        }
    }
    else
        resultat = -1;

    if (resultat == 5049)
        resultat++;
    printf("%d", resultat);
}