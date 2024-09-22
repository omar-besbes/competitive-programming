#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k, g = 0, ans = 0;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        if (a >= k)
            g += a;
        if (a == 0 && g > 0)
        {
            g--, ans++;
        }
    }
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