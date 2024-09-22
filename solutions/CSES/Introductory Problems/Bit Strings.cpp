#include "bits/stdc++.h"
using namespace std;

const int mod = 1e9 + 7;

long long binexp(long long a, long long b)
{
    if (b == 0)
        return 1;
    auto res = binexp(a, b / 2);
    if (b & 1)
        return res * res * a % mod;
    else
        return res * res % mod;
}

int main()
{
    int n;
    cin >> n;
    cout << binexp(2, n) << "\n";
}