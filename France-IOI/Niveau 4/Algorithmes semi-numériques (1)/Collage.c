#include <stdio.h>
#include <stdlib.h>

int PGCD(int A, int B)
{
    if (B > A)
    {
        int C = B;
        B = A;
        A = C;
    }
    int x = A % B;
    if (x)
        return PGCD(x, B);
    return B;
}

int main()
{
    int L, D;
    scanf("%d %d", &L, &D);
    printf("%d", (L * D) / PGCD(L, D));
    return 0;
}