#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int X, Y, N;
    scanf("%d %d %d", &X, &Y, &N);
    int Point[N][2];
    float distance;
    scanf("%d %d", Point[0], Point[0] + 1);
    distance = sqrt(pow((Point[0][0] - X), 2) + pow((Point[0][1] - Y), 2));
    int Xp = Point[0][0], Yp = Point[0][1];
    for (int i = 1; i < N; i++)
    {
        scanf("%d %d", Point[i], Point[i] + 1);
        float d = sqrt(pow((Point[i][0] - X), 2) + pow((Point[i][1] - Y), 2));
        if (distance > d)
        {
            distance = d;
            Xp = Point[i][0];
            Yp = Point[i][1];
        }
    }
    printf("%d %d", Xp, Yp);

    return 0;
}