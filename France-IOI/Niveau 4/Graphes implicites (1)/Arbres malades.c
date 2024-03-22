#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Arbres
{
    int X, Y, R, C;
} Arb;

void Reset(Arb *A, int N)
{
    for (int i = 0; i < N; i++)
        A[i].C = 0;
}

int Distance(Arb Malade, Arb Sain)
{
    int d = pow(Malade.X - Sain.X, 2) + pow(Malade.Y - Sain.Y, 2);
    return pow(Malade.R, 2) - d;
}

int Contamination_(int pos, Arb *T, int N, int **Distances)
{
    int contamine = 1;
    for (int i = 0; i < N; i++)
        if (!T[i].C && Distances[pos][i] >= 0)
        {
            T[i].C = 1;
            contamine += Contamination_(i, T, N, Distances);
        }
    return contamine;
}

int main()
{
    int N, M;
    scanf("%d %d", &N, &M);
    Arb *Tree = (Arb *)malloc(N * sizeof(Arb));
    for (int i = 0; i < N; i++)
    {
        scanf("%d %d %d", &Tree[i].X, &Tree[i].Y, &Tree[i].R);
        Tree[i].C = 0;
    }

    int **Distances = (int **)malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++)
    {
        Distances[i] = (int *)malloc(N * sizeof(int));
        for (int j = 0; j < N; j++)
            Distances[i][j] = Distance(Tree[i], Tree[j]);
    }

    for (int i = 0; i < M; i++)
    {
        Reset(Tree, N);
        int pos;
        scanf("%d", &pos);
        Tree[pos].C = 1;
        printf("%d\n", Contamination_(pos, Tree, N, Distances));
    }

    return 0;
}