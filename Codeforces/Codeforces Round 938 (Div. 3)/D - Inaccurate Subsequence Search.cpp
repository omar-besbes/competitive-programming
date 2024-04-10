#include "bits/stdc++.h"
using namespace std;

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n), b(m);
    map<int, int> occ, occb;
    for (auto &i : a)
        cin >> i;
    for (auto &i : b)
    {
        cin >> i;
        occb[i]++;
    };

    int match = 0;
    for (int i = 0; i < m; i++)
        occ[a[i]]++;
    for (auto [k, v] : occ)
        match += min(v, occb[k]);

    int ans = (match >= k ? 1 : 0);
    for (int i = m; i < n; i++)
    {
        if (a[i] != a[i - m])
        {
            match -= min(occ[a[i - m]], occb[a[i - m]]);
            match -= min(occ[a[i]], occb[a[i]]);
            occ[a[i - m]]--;
            occ[a[i]]++;
            match += min(occ[a[i - m]], occb[a[i - m]]);
            match += min(occ[a[i]], occb[a[i]]);
        }

        // cout << i << " " << match << " " << k << "\n";
        if (match >= k)
            ans++;
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