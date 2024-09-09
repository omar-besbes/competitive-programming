#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void transformer(char *s, char *ch, int i)
{
    ch[0] = s[i];
    strcpy(ch + 1, s);
    strcpy(ch + i + 1, s + i + 1);
}

int arrangement(int n, int p)
{
    int x = 1;
    for (int i = n; i > n - p; i--)
        x *= i;
    return x;
}

void ecrire(int L, int niveau, char *s)
{
    if (L - niveau)
    {
        int c = strlen(s) - niveau;
        for (int i = 0; i < c; i++)
        {
            char ch[strlen(s) + 1];
            strcpy(ch, s);
            transformer(s + niveau, ch + niveau, i);
            ecrire(L, niveau + 1, ch);
        }
        return;
    }
    for (int i = 0; i < L; i++)
        printf("%c", s[i]);
    printf("\n");
}

int main()
{
    int L, N;
    scanf("%d", &L);
    char *lettre = (char *)malloc((L + 1) * sizeof(char));
    lettre[L] = '\0';
    fflush(stdin);
    scanf("%s", lettre);
    scanf("%d", &N);
    printf("%d\n", arrangement(L, N));
    ecrire(N, 0, lettre);
    return 0;
}