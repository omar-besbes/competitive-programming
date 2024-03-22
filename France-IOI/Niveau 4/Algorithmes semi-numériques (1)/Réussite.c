#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, Premier[79000], indice = 5;
    Premier[0] = 0;
    Premier[1] = 1;
    Premier[2] = 2;
    Premier[3] = 3;
    Premier[4] = 5;
    scanf("%d", &N);
    printf("0\n1\n2\n3\n5\n");
    for (int i = 6; i <= N; i++)
    {
        int test = 1;

        for (int j = 2; Premier[j] * Premier[j] <= i && j < indice; j++)
            if (i % Premier[j] == 0)
            {
                test = 0;
                break;
            }

        if (test)
        {
            printf("%d\n", i);
            Premier[indice++] = i;
        }
    }
    return 0;
}