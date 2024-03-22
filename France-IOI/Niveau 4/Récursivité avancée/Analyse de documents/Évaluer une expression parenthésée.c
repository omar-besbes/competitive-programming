#include <stdio.h>
#include <stdlib.h>

int Calculer()
{
    char c, op;
    int n = 0, x = 0;
    if (!scanf("%d", &n))
    {
        scanf("%c", &c);
        n = Calculer();
    }
    scanf("%c", &op);
    if (!scanf("%d", &x))
    {
        scanf("%c", &c);
        x = Calculer();
    }
    switch (op)
    {
    case '+':
        n += x;
        break;
    case '-':
        n -= x;
        break;
    case '*':
        n *= x;
        break;
    case '/':
        n /= x;
        break;
    case '%':
        n %= x;
        break;
    }
    scanf("%c", &c);
    return n;
}

int main()
{
    int n;
    char c;
    if (scanf("%d", &n))
        printf("%d", n);
    else
    {
        scanf("%c", &c);
        printf("%d", Calculer());
    }
    return 0;
}