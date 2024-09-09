#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct tableau_2D
{
    int K, deg;
} tab_2D;

void deg(int K, int *Recipient, int *Degre, int Nb)
{
    if (Recipient[K - 1] == 0)
        Degre[K - 1] = 2;
    else
    {
        if (Degre[Recipient[K - 1] - 1] == -1)
            deg(Recipient[K - 1], Recipient, Degre, Nb);
        Degre[K - 1] = Degre[Recipient[K - 1] - 1] + 1;
    }
}

int s_to_i(char *s)
{
    int n = strlen(s), x = 0;
    for (int i = 0; i < n; i++)
        x += (s[i] - 48) * pow(10, n - i - 1);
    return x;
}

void Parcourir(int pos, char *s, int n, int *Recipient, int *Degre, tab_2D *Perdu, int Nb)
{
    if (pos < n && s[pos] == '?')
    {
        int i = (pos) ? 0 : 1;
        while (i < 10)
        {
            s[pos] = 48 + i++;
            Parcourir(pos + 1, s, n, Recipient, Degre, Perdu, Nb);
        }
        s[pos] = '?';
    }
    if (pos < n && s[pos] != '?')
        Parcourir(pos + 1, s, n, Recipient, Degre, Perdu, Nb);
    if (pos >= n)
    {
        int K = s_to_i(s);
        Perdu[K - 1].K = K;
        if (K > Nb)
            return;
        deg(K, Recipient, Degre, Nb);
        Perdu[K - 1].deg = Degre[K - 1];
    }
}

void Permuter(int *A, int *B)
{
    int C = *A;
    *A = *B;
    *B = C;
}

void Tri(tab_2D *Perdu, int n)
{
    int i = 0;
    while (i < n && Perdu[i].deg == -1)
        i++;
    i++;
    while (i < n)
    {
        int j = i;
        while (j && Perdu[j].deg < Perdu[j - 1].deg)
        {
            Permuter(&Perdu[j].deg, &Perdu[j - 1].deg);
            Permuter(&Perdu[j].K, &Perdu[j - 1].K);
            j--;
        }
        i++;
    }
}

int main()
{
    int N, *Recipient, *Degre;
    tab_2D *Perdu;
    scanf("%d", &N);
    Recipient = (int *)malloc(N * sizeof(int));
    Degre = (int *)malloc(N * sizeof(int));
    Perdu = (tab_2D *)malloc(N * sizeof(tab_2D));
    for (int i = 0; i < N; i++)
    {
        scanf("%d ", &Recipient[i]);
        Degre[i] = -1;
        Perdu[i].deg = -1;
    }
    char s[6];
    scanf("%s", s);

    Parcourir(0, s, strlen(s), Recipient, Degre, Perdu, N);
    Tri(Perdu, N);
    int i = 0;
    while (Perdu[i].deg == -1)
        i++;
    while (i < N)
        printf("%d ", Perdu[i++].K);
    return 0;
}