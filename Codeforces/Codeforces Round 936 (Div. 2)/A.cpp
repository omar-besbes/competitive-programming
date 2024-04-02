#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a, a + n);
        int med = (n + 1) / 2 - 1, res = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[med + i] == a[med])
                res++;
            else
                break;
        }
        cout << res << "\n";
    }

    return 0;
}