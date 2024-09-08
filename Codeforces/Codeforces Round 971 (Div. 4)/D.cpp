#include "bits/stdc++.h"
using namespace std;

void solve()
{
    int n;
    cin >> n;
    set<int> x0, x1;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        if (b == 0)
            x0.insert(a);
        else
            x1.insert(a);
    }

    long long ans = 0;
    for (auto i : x0)
    {
        if (x1.find(i) != x1.end())
            ans += n - 2;
        if (x1.find(i - 1) != x1.end() && x1.find(i + 1) != x1.end())
            ans++;
    }

    for (auto i : x1)
    {
        if (x0.find(i - 1) != x0.end() && x0.find(i + 1) != x0.end())
            ans++;
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