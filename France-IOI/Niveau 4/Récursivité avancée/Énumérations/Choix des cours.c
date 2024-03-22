#include <stdio.h>
#include <stdlib.h>

void Afficher(int *T, int N)
{
    for (int i = 0; i < N - 1; i++)
        printf("%d ", T[i]);
    printf("%d", T[N - 1]);
    printf("\n");
}

void Combinaison(int *Choix, int nbCours, int nbChoix, int dernier, int *test)
{
    if (dernier < 0)
        *test = 0;
    if (*test)
    {
        if (dernier == nbChoix - 1)
        {
            Choix[dernier] = Choix[dernier - 1] + 1;
            while (Choix[dernier] <= nbCours)
            {
                Afficher(Choix, nbChoix);
                Choix[dernier]++;
            }
            Combinaison(Choix, nbCours, nbChoix, dernier - 1, test);
            Combinaison(Choix, nbCours, nbChoix, dernier, test);
        }
        else if (Choix[dernier]++ == nbCours - nbChoix + dernier + 1)
        {
            Choix[dernier] = Choix[dernier - 1];
            Combinaison(Choix, nbCours, nbChoix, dernier - 1, test);
            Choix[dernier] = Choix[dernier - 1] + 1;
        }
    }
}

int main()
{
    int nbCours, nbChoix, test = 1;
    scanf("%d %d", &nbCours, &nbChoix);
    int *Choix = (int *)malloc(nbChoix * sizeof(int));
    for (int i = 0; i < nbChoix; i++)
        Choix[i] = i + 1;
    if (nbChoix <= nbCours)
        Combinaison(Choix, nbCours, nbChoix, nbChoix - 1, &test);

    return 0;
}