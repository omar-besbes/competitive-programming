#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void operer(int NC, int C[NC], int Act, int operation)
{
    int A = operation;
    // vider = 0, remplir = 1
    if (Act == 1 && C[Act] == 1 - A && C[0] == 1)
    {
        C[Act] = A;
        printf("%d\n", Act + 1);
    }
    else if (Act == 0 && C[Act] == 1 - A)
    {
        C[Act] = A;
        printf("%d\n", Act + 1);
    }
    else
    {
        if (C[Act - 1] == 0 && Act != 0)
            operer(NC, C, Act - 1, 1);
        for (int verifier = Act - 2; verifier >= 0; verifier--)
            if (C[verifier] == 1)
                operer(NC, C, verifier, 0);
        C[Act] = A;
        printf("%d\n", Act + 1);
    }
}

int main()
{
    int Nombre_Cases;
    scanf(" %d", &Nombre_Cases);

    int Cases[Nombre_Cases];
    for (int Act = 0; Act < Nombre_Cases; Act++)
        Cases[Act] = 1;

    int Actuel = Nombre_Cases - 1;
    while (Actuel >= 0)
    {
        operer(Nombre_Cases, Cases, Actuel, 0);
        Actuel--;
    }
}