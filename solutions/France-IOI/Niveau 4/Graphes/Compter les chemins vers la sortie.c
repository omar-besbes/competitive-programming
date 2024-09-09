#include <stdio.h>
#include <stdlib.h>

struct Labyrinthe
{
    char Case;
    int visite;
};

int Parcourir(int x, int y, struct Labyrinthe **Cases, int L, int C)
{
    int Ywassal = 0;
    Cases[y][x].visite = 1;
    if (y == L - 1 && x == C - 2)
        Ywassal++;
    if (y + 1 < L && Cases[y + 1][x].Case == '.' && !Cases[y + 1][x].visite)
    {
        Ywassal += Parcourir(x, y + 1, Cases, L, C);
        Cases[y + 1][x].visite = 0;
    }
    if (y - 1 > 0 && Cases[y - 1][x].Case == '.' && !Cases[y - 1][x].visite)
    {
        Ywassal += Parcourir(x, y - 1, Cases, L, C);
        Cases[y - 1][x].visite = 0;
    }
    if (x + 1 < C && Cases[y][x + 1].Case == '.' && !Cases[y][x + 1].visite)
    {
        Ywassal += Parcourir(x + 1, y, Cases, L, C);
        Cases[y][x + 1].visite = 0;
    }
    if (x - 1 > 0 && Cases[y][x - 1].Case == '.' && !Cases[y][x - 1].visite)
    {
        Ywassal += Parcourir(x - 1, y, Cases, L, C);
        Cases[y][x - 1].visite = 0;
    }
    return Ywassal;
}

int main()
{
    int L, C;
    scanf("%d %d", &L, &C);
    struct Labyrinthe **Cases = (struct Labyrinthe **)malloc(L * sizeof(struct Labyrinthe *));
    getchar();
    for (int i = 0; i < L; i++)
    {
        Cases[i] = (struct Labyrinthe *)malloc(C * sizeof(struct Labyrinthe));
        for (int j = 0; j < C; j++)
        {
            scanf("%c", &Cases[i][j].Case);
            Cases[i][j].visite = 0;
        }
        getchar();
    }

    printf("%d", Parcourir(0, 1, Cases, L, C));
    return 0;
}