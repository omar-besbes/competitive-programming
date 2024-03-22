#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int Xa, Ya, Xb, Yb;
    scanf("%d %d %d %d", &Xa, &Ya, &Xb, &Yb);
    int X, Y, N;
    int a = Xb - Xa, b = Yb - Ya;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d %d", &X, &Y);
        int c = X - Xa, d = Y - Ya;
        float distance = (a * c + b * d) / sqrt(a * a + b * b);
        printf("%f\n", distance);
    }

    return 0;
}