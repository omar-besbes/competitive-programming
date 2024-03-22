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
        int Somme = M1[M - 1 - i] + M2[M - 1 - i] + S[M - 1 - i];
        S[M - 1 - i] = Somme % B;
        S[M - 2 - i] = Somme / B;
    }
    if (S[0])
        printf("%d ", S[0]);
    for (int i = 1; i < M; i++)
        printf("%d ", S[i]);

    return 0;
}