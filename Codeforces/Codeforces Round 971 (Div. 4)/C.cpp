#include "bits/stdc++.h"
using namespace std;

void solve()
{
    long long x, y, k;
    cin >> x >> y >> k;
    x = ceil((double)x / k);
    y = ceil((double)y / k);

    long long ans;
    if (x > y)
        ans = x + x - 1;
    else
        ans = 2 * y;
    cout << ans << "\n";
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