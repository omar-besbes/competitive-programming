#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

int compareEntier(const void *pEntier1, const void *pEntier2)
{
    return (*(int *)(pEntier1) - *(int *)(pEntier2));
}

bool estSouple(int ListeS, int ObjetsS[ListeS], int Averifier)
{
    int Moy1 = ListeS / 4;
    int Moy2 = 2 * Moy1, Moy3 = 3 * Moy1;
    bool resultat = false;

    if (Averifier < ObjetsS[Moy1])
    {
        for (int O = 0; O < Moy1; O++)
            if (Averifier == ObjetsS[O])
            {
                resultat = true;
                break;
            }
            else if (Averifier < ObjetsS[O])
                break;
    }
    else if (Averifier < ObjetsS[Moy2])
    {
        for (int O = Moy1; O < Moy2; O++)
            if (Averifier == ObjetsS[O])
            {
                resultat = true;
                break;
            }
            else if (Averifier < ObjetsS[O])
                break;
    }
    else if (Averifier < ObjetsS[Moy3])
    {
        for (int O = Moy2; O < Moy3; O++)
            if (Averifier == ObjetsS[O])
            {
                resultat = true;
                break;
            }
            else if (Averifier < ObjetsS[O])
                break;
    }
    else
    {
        for (int O = Moy3; O < ListeS; O++)
            if (Averifier == ObjetsS[O])
            {
                resultat = true;
                break;
            }
            else if (Averifier < ObjetsS[O])
                break;
    }

    return resultat;
}

int main()
{
    int ListeS;
    scanf(" %d", &ListeS);
    int ObjetsS[ListeS];
    for (int Objet = 0; Objet < ListeS; Objet++)
        scanf(" %d", &ObjetsS[Objet]);
    qsort(ObjetsS, ListeS, 4, compareEntier);

    int resultat = 0;
    int ListeP;
    scanf(" %d", &ListeP);
    int ObjetsP[ListeP];
    for (int Objet = 0; Objet < ListeP; Objet++)
    {
        scanf(" %d", &ObjetsP[Objet]);

        if (estSouple(ListeS, ObjetsS, ObjetsP[Objet]))
            resultat++;
    }

    printf("%d", resultat);
}