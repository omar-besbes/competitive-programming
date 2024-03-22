#include <stdio.h>

int pgcd(int N, int P)
{
    while (1)
    {
        if (N > P)
            N %= P;
        else
            P %= N;
        if (P == 0)
            return N;
        if (N == 0)
            return P;
    }
}

int main()
{
    int N, P;
    scanf("%d %d", &N, &P);
    printf("%d", pgcd(N, P));

    return 0;
}