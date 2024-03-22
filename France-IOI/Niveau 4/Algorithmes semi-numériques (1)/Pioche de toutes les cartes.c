#include <stdio.h>
#include <math.h>

int main()
{
    int N;
    double ordre = 1;
    scanf("%d", &N);
    for (int i = 2; i <= N; i++)
        ordre *= i;
    printf("%d", (int)ordre);

    return 0;
}