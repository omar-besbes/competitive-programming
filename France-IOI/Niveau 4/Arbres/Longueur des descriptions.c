#include <stdio.h>
#include <stdlib.h>

struct Objet
{
    int id;
    int recipient;
    int degree;
};

void Degre(struct Objet *K, int i)
{
    int RECIPIENT_ID = (K + i)->recipient;
    int RECIPIENT_DEGREE = (K + RECIPIENT_ID - 1)->degree;
    if (RECIPIENT_ID == 0)
        (K + i)->degree = 1;
    else
    {
        if (RECIPIENT_DEGREE != -1)
            (K + i)->degree = RECIPIENT_DEGREE + 1;
        else
        {
            Degre(K, RECIPIENT_ID - 1);
            RECIPIENT_DEGREE = (K + RECIPIENT_ID - 1)->degree;
            (K + i)->degree = RECIPIENT_DEGREE + 1;
        }
    }
}

int main()
{
    int N;
    struct Objet *K;
    scanf("%d", &N);
    K = (struct Objet *)malloc(N * sizeof(struct Objet));
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &(K[i].recipient));
        (K + i)->id = i + 1;
        (K + i)->degree = -1;
    }
    int max = 0;
    for (int i = 0; i < N; i++)
    {
        Degre(K, i);
        if (max < (K + i)->degree)
            max = (K + i)->degree;
    }
    printf("%d\n", max);

    return 0;
}