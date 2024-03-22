#include <stdio.h>

void afficher(int K, int N, int *sejour)
{
    for (int i = 0; i < N; i++)
        printf("%d ", sejour[i]);
    printf("\n");
}

int calculer(int K, int N, int *sejour, int *i)
{
    if ((sejour[*i] == K) && (*i > 0))
    {
        int c = *i;
        (*i)--;
        sejour[c] = calculer(K, N, sejour, i);
        return sejour[c];
    }
    else
    {
        afficher(K, N, sejour);
        sejour[*i]++;
        return sejour[*i];
    }
}

int main()
{
    int N, K;
    scanf("%d %d", &K, &N);
    int sejour[N];
    for (int i = 0; i < N; i++)
        sejour[i] = 1;

    int i = N - 1, wehed;
    while (sejour[0] != K)
    {
        wehed = calculer(K, N, sejour, &i);
        i = wehed;
        i = N - 1;
    }
    afficher(K, N, sejour);

    return 0;
}