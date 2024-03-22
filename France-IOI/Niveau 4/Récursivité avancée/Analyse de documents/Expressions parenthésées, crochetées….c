#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Est_parenthese(char *phrase, int n, int *i, int degre)
{
    int thalchi = 0, mrigla = 1, mrigla_deg;
    char chnowa;
    while (*i < n)
    {
        switch (phrase[*i])
        {
        case '{':
        case '(':
        case '[':
        case '<':
        {
            if (thalchi == 0)
            {
                chnowa = phrase[*i];
                thalchi = 1;
                mrigla = 0;
            }
            else
                mrigla_deg = Est_parenthese(phrase, n, i, degre + 1);

            break;
        }
        case '}':
        case ')':
        case ']':
        case '>':
        {
            if (thalchi == 0)
                mrigla = 0;
            else if (chnowa + 2 != phrase[*i] && chnowa + 1 != phrase[*i])
                return 0;
            else
            {
                mrigla = 1;
                thalchi = 0;
            }

            if (degre != 0)
                return mrigla;

            break;
        }
        }
        if (mrigla_deg == 0)
            break;
        (*i)++;
    }
    if (mrigla_deg == 0)
        return 0;
    return mrigla;
}

int main()
{
    char phrase[201];
    gets(phrase);
    int i = 0, R = Est_parenthese(phrase, (int)strlen(phrase), &i, 0);
    if (R == 1)
        printf("yes");
    else
        printf("no");

    return 0;
}