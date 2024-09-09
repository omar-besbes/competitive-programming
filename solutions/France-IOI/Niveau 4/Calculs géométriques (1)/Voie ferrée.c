#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int Xa, Ya, Xb, Yb;
    scanf("%d %d %d %d", &Xa, &Ya, &Xb, &Yb);
    int X, Y, N, Xt, Yt;
    int a = Xb - Xa, b = Yb - Ya;
    float distance = 0;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d %d", &X, &Y);
        int c = X - Xa, d = Y - Ya;
        int D = abs(a * d - b * c) / sqrt(a * a + b * b);
        if (distance < D)
        {
            distance = D;
            Xt = X;
            Yt = Y;
        }
    }
    printf("%d %d", Xt, Yt);

    return 0;
}