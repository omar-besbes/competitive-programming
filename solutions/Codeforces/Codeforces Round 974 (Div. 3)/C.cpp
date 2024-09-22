#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    int n;
    cin >> n;
    ll sum = 0;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }

    if (n == 1 || n == 2)
        cout << "-1\n";
    else
    {
        sort(a.begin(), a.end());

        ll l = 0, r = 1e18;
        while (l < r)
        {
            ll m = (l + r) / 2;
            ll avg = ((sum + m) / (2 * n)) + ((sum + m) % (2 * n) ? 1 : 0);
            int nb = lower_bound(a.begin(), a.end(), avg) - a.begin();
            if (nb > n / 2)
                r = m;
            else
                l = m + 1;
        }

        cout << r << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--)
        solve();
}