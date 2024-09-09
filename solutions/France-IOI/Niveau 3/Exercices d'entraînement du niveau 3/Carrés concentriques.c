#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int L;
    scanf(" %d", &L);
    char ligne[L];
    scanf(" %s", ligne);

    char sortie[L * 2 - 1][L * 2 - 1];
    for (int lettre = L * 2 - 2; lettre >= 0; lettre--)
    {
        int coins[2] = {L * 2 - 2 - lettre, lettre};
        for (int X = coins[0]; X <= coins[1]; X++)
            for (int Y = coins[0]; Y <= coins[1]; Y++)
                sortie[X][Y] = ligne[lettre - L + 1];
    }

    for (int X = 0; X < L * 2 - 1; X++)
    {
        for (int Y = 0; Y < L * 2 - 1; Y++)
            printf("%c", sortie[X][Y]);
        printf("\n");
    }
}