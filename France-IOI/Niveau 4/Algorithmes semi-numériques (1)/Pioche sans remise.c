#include <stdio.h>
#include <math.h>

int main()
{
    int N, P;
    float ordre = 1;
    scanf("%d %d", &N, &P);
    for (int i = N; i > N - P; i--)
        ordre *= i;
    printf("%d", (int)ordre);

    return 0;
}