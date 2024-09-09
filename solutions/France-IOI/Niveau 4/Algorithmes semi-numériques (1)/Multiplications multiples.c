#include <stdio.h>
#include <stdlib.h>

int main()
{
    long int N, X = 1, A;
    scanf("%ld", &N);
    for (long int i = 0; i < N; i++)
    {
        scanf("%ld", &A);
        X *= A;
        X %= 10000;
    }
    printf("%04ld", X);

    return 0;
}