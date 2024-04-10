#include "bits/stdc++.h"
using namespace std;

void solve()
{
    long long n, k;
    cin >> n >> k;
    vector<long long> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    long long ans = 0;
    for (long long i = 0, j = n - 1; k > 0 && i <= j && i < n && j < n;)
    {
        // for(auto i: a) cout << i << " "; cout << "\n";

        if (i == j)
        {
            long long diff = min(k, 1ll * a[i]);
            k -= diff;
            a[i] -= diff;
            if (a[i] <= 0)
                i++, ans++;
        }
        else
        {
            long long diff = min(k, 2ll * min(a[j], a[i]));
            k -= diff;
            a[i] -= diff - diff / 2;
            a[j] -= diff / 2;
            if (a[j] <= 0)
                j--, ans++;
            if (a[i] <= 0)
                i++, ans++;
        }
    }

    cout << ans << "\n";
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