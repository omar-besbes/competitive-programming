#include <stdio.h>
#include <stdlib.h>

int main()
{
    int Aeroport[4], N;
    for (int i = 0; i < 4; i++)
        scanf("%d", Aeroport + i);
    scanf("%d", &N);
    int Prive[N][4], surface = (Aeroport[2] - Aeroport[0]) * (Aeroport[3] - Aeroport[1]);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 4; j++)
            scanf("%d", Prive[i] + j);
        if (Prive[i][0] > Aeroport[2] || Prive[i][1] > Aeroport[3])
            continue;
        if (Prive[i][2] < Aeroport[0] || Prive[i][3] < Aeroport[1])
            continue;
        if (Prive[i][0] < Aeroport[0])
            Prive[i][0] = Aeroport[0];
        if (Prive[i][1] < Aeroport[1])
            Prive[i][1] = Aeroport[1];
        if (Prive[i][2] > Aeroport[2])
            Prive[i][2] = Aeroport[2];
        if (Prive[i][3] > Aeroport[3])
            Prive[i][3] = Aeroport[3];
        surface -= (Prive[i][2] - Prive[i][0]) * (Prive[i][3] - Prive[i][1]);
    }
    printf("%d", surface);

    return 0;
}