#include "bits/stdc++.h"
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<long long> a(n);
    for (auto &i : a)
        cin >> i;

    if (n == 1)
    {
        cout << "2\n";
        return;
    }

    long long x = abs(a[1] - a[0]);
    for (int i = 2; i < n; i++)
    {
        x = gcd(x, abs(a[i] - a[i - 1]));
    }

    if (x > 1)
    {
        for (long long d = 2; d * d <= x; d++)
        {
            if (x % d == 0)
            {
                x = d;
                break;
            }
        }
    }

    cout << (x != 1 ? max(x, 2ll) : -1) << "\n";
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
