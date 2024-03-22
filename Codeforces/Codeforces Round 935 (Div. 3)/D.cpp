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
        int n, m;
        cin >> n >> m;

        int a[n], b[n];
        long long prefb[n + 1];
        prefb[0] = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
            prefb[i + 1] = b[i] + prefb[i];
        }

        long long res = 0;
        for (int i = n - 1; i > m - 1; i--)
        {
            res += min(a[i], b[i]);
        }

        long long tmp = a[m - 1];
        for (int i = 0; i < m; i++)
        {
            tmp = min(tmp, a[i] + prefb[m] - prefb[i + 1]);
        }

        res += tmp;

        cout << res << "\n";
    }
}
