#include "bits/stdc++.h"
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    if (n == k)
    {
        for (int i = 0; i < n; i++)
            cout << 1 << " ";
    }
    else if (k == 1)
    {
        for (int i = 0; i < n; i++)
            cout << i + 1 << " ";
    }
    else
    {
        cout << -1;
    }
    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        solve();
}