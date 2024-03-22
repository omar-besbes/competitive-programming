#include <stdio.h>
#include <stdlib.h>

struct Labyrinthe
{
    char Case;
    int visite;
};

int Deplacement_ligne[4] = {0, 0, 1, -1};
int Deplacement_colonne[4] = {1, -1, 0, 0};

int Verification(int X, int Y, struct Labyrinthe **Cases, int L, int C)
{
    if (X >= 0 && X < C)
        if (Y >= 0 && Y < L)
            if (!Cases[Y][X].visite)
                if (Cases[Y][X].Case == '.')
                    return 1;
    return 0;
}

int Parcourir(int x, int y, struct Labyrinthe **Cases, int L, int C)
{
    int nbVisites = 1;
    Cases[y][x].visite = 1;
    for (int i = 0; i < 4; i++)
    {
        int X = x + Deplacement_colonne[i];
        int Y = y + Deplacement_ligne[i];
        if (Verification(X, Y, Cases, L, C))
            nbVisites += Parcourir(X, Y, Cases, L, C);
    }
    return nbVisites;
}

int main()
{
    int L, C, nbCasesLibres = 0;
    scanf("%d %d", &L, &C);
    struct Labyrinthe **Cases = (struct Labyrinthe **)malloc(L * sizeof(struct Labyrinthe *));
    getchar();
    for (int i = 0; i < L; i++)
    {
        Cases[i] = (struct Labyrinthe *)malloc(C * sizeof(struct Labyrinthe));
        for (int j = 0; j < C; j++)
        {
            scanf("%c", &Cases[i][j].Case);
            if (Cases[i][j].Case == '.')
                nbCasesLibres++;
            Cases[i][j].visite = 0;
        }
        getchar();
    }

    printf("%d", nbCasesLibres - Parcourir(0, 1, Cases, L, C));
    return 0;
}