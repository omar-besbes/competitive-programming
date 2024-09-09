#include <stdio.h>
#include <stdlib.h>

void Affichage(int **Carton, int *Ordre_Cartons, int i, int j)
{
    int C = Carton[i][j];
    if (C != -1)
    {
        for (j = 0; Carton[i][j] != -1; j++)
        {
            C = Carton[i][j];
            printf("A %d\n", C);
            Affichage(Carton, Ordre_Cartons, Carton[i][j], 0);
        }
        if (i != 0)
            printf("R %d\n", i);
    }
    else if (i != 0)
        printf("R %d\n", i);
}

int main()
{
    int Nb_Cartons, **Carton, *Ordre_Cartons;
    scanf("%d", &Nb_Cartons);
    Nb_Cartons++;
    Carton = (int **)malloc(Nb_Cartons * sizeof(int *));
    Ordre_Cartons = (int *)malloc(Nb_Cartons * sizeof(int));
    for (int i = 0; i < Nb_Cartons; i++)
    {
        scanf("%d", Ordre_Cartons + i);
        *(Carton + i) = (int *)malloc((*(Ordre_Cartons + i) + 1) * sizeof(int));
        int j;
        for (j = 0; j < *(Ordre_Cartons + i); j++)
            scanf("%d", &Carton[i][j]);
        Carton[i][j] = -1;
    }

    Affichage(Carton, Ordre_Cartons, 0, 0);

    return 0;
}