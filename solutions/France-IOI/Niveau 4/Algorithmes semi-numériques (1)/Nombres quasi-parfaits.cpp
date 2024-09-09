#include "bits/stdc++.h"
using namespace std;

#define N 1000000 + 1

long long s[N];

void init()
{
    s[0] = s[1] = 0;
    for (int i = 2; i < N; i++)
    {
        // 1 is a divisor for all integers
        s[i]++;
        for (int j = 2 * i; j < N; j += i)
        {
            s[j] += i;
        }
    }
}

int main()
{
    int l, d;
    cin >> l >> d;

    init();

    int res = 0;
    for (int i = 0; i < l; i++)
    {
        if (abs(s[i + 1] - (i + 1)) <= d)
            res++;
    }
    cout << res;

    return 0;
}