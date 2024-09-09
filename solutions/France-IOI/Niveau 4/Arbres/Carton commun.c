#include <stdio.h>
#include <stdlib.h>

struct Objet
{
    int id;
    int recipient;
};

int main()
{
    int N, R;
    struct Objet *K;
    scanf("%d", &N);
    K = (struct Objet *)malloc(N * sizeof(struct Objet));
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &(K[i].recipient));
        (K + i)->id = i + 1;
    }
    scanf("%d", &R);
    for (int i = 0; i < R; i++)
    {
        int R1, R2;
        scanf("%d %d", &R1, &R2);
        int _R1 = R1;
        while (_R1 != R2 && R2 != 0)
        {
            _R1 = R1;
            while (_R1 != R2 && _R1 != 0)
                _R1 = K[_R1 - 1].recipient;
            if (_R1 == R2)
                break;
            R2 = K[R2 - 1].recipient;
        }
        printf("%d\n", R2);
    }

    return 0;
}