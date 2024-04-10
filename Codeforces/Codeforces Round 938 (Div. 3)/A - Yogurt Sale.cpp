#include "bits/stdc++.h"
using namespace std;

void solve()
{
    int n, a, b;
    cin >> n >> a >> b;
    int ans = n & 1 ? ((n - 1) / 2) * min(2 * a, b) + a : (n / 2) * min(2 * a, b);
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