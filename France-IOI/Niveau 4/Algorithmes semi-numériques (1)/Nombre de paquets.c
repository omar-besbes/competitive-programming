#include <stdio.h>

int combinaison(int N, int P)
{
    double C = 1;
    for (int i = N; i > N - P; i--)
        C *= i;
    for (int i = 1; i <= P; i++)
        C /= i;
    return (int)C;
}

int main()
{
    int N, P;
    scanf("%d %d", &N, &P);
    printf("%d", combinaison(N, P));

    return 0;
}