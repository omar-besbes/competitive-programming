#include "bits/stdc++.h"

using namespace std;

int main()
{
    unsigned int n, p;
    cin >> n >> p;
    unsigned long long res = 0;
    for (unsigned long long i = p; i <= n; i *= p)
    {
        res += n / i;
    }

    cout << res << "\n";
}