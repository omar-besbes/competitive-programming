#include <stdio.h>
#include <stdlib.h>

int Max(int A, int B)
{
    return (A > B) ? A : B;
}

int main()
{
    int B, N1, N2;
    scanf("%d %d %d", &B, &N1, &N2);
    int *M1, *M2, *S, M = Max(N1, N2) + 1;
    M1 = (int *)malloc(M * sizeof(int));
    M2 = (int *)malloc(M * sizeof(int));
    S = (int *)malloc(M * sizeof(int));
    S[M - 1] = 0;
    for (int i = 0; i < M - N1; i++)
        M1[i] = 0;
    for (int i = 0; i < M - N2; i++)
        M2[i] = 0;
    for (int i = M - N1; i < M; i++)
        scanf("%d", M1 + i);
    for (int i = M - N2; i < M; i++)
        scanf("%d", M2 + i);
    for (int i = 0; i < M - 1; i++)
    {
        int Somme = M1[M - 1 - i] - M2[M - 1 - i] + S[M - 1 - i];
        if (Somme < 0)
        {
            Somme += B;
            S[M - 1 - i] = Somme;
            S[M - 2 - i] = -1;
        }
        else
        {
            S[M - 1 - i] = Somme;
            S[M - 2 - i] = 0;
        }
    }
    if (S[0] == -1)
    {
        printf("- ");
        for (int i = 1; i < M; i++)
            S[i] = B - 1 - S[i];
        S[M - 1]++;
        int indice = 0;
        while (S[M - 1 - indice] == B)
        {
            S[M - 1 - indice] = 0;
            indice++;
            S[M - 1 - indice]++;
        }
    }
    int j = 1;
    while (!S[j] && j < M - 1)
        j++;
    for (int i = j; i < M; i++)
        printf("%d ", S[i]);

    return 0;
}