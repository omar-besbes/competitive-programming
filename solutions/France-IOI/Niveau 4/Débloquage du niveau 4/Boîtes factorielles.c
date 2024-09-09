#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int fac(int nombre)
{
    if (nombre > 1)
        nombre *= fac(nombre - 1);
    return nombre;
}

int main()
{
    int Nombre_PP;
    scanf(" %d", &Nombre_PP);

    int top = 12;
    while (Nombre_PP < fac(top))
        top--;

    printf("%d\n", top);
    int Suite[top];
    for (int bot = top; bot > 0; bot--)
    {
        Suite[bot - 1] = Nombre_PP / fac(bot);
        Nombre_PP %= fac(bot);
    }

    for (int N = 0; N < top; N++)
        printf("%d ", Suite[N]);
}