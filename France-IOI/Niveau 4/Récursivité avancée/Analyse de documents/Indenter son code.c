#include <stdio.h>

void accolade(int deg)
{
    char carLu = 'a';
    while (carLu != '\n')
    {
        scanf("%c", &carLu);
        if (carLu == '{')
        {
            int i = deg;
            while (i > 0)
            {
                printf("   ");
                i--;
            }
            printf("%c\n", carLu);
            accolade(deg + 1);
        }
        else
        {
            int i = deg - 1;
            while (i > 0)
            {
                printf("   ");
                i--;
            }
            printf("%c\n", carLu);
            return;
        }
    }
    return;
}

int main()
{
    accolade(0);
    return 0;
}