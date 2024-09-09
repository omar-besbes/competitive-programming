#include "bits/stdc++.h"
using namespace std;

int main()
{
    int n;
    cin >> n;
    int b[n];
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    sort(b, b + n);
    int q;
    cin >> q;
    while (q--)
    {
        int d;
        cin >> d;
        auto res = binary_search(b, b + n, d);
        cout << (res ? 1 : 0) << "\n";
    }
    return 0;
}