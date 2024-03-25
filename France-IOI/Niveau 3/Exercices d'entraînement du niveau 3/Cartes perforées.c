#include <stdio.h>

int main()
{
    int NbLignes;
    scanf(" %d", &NbLignes);

    char Lettre;
    for (int Ligne = 0; Ligne < NbLignes; Ligne++)
        for (int Colonne = 0; Colonne < 26; Colonne++)
        {
            scanf(" %c", &Lettre);
            if (Lettre == 'O')
                printf("%c", 65 + Colonne);
        }
}