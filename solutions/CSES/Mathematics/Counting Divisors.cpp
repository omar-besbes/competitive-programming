#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int x;
    cin >> x;
    int ans = (x > 1 ? 2 : 1);
    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
            ans += (x / i == i) ? 1 : 2;
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