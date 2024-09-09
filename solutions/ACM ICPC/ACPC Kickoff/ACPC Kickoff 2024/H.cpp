#include "bits/stdc++.h"
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int p = n / m;
    if (p >= 150)
        cout << "VERY HAPPY";
    else if (p >= 100)
        cout << "HAPPY";
    else
        cout << "SAD";
}