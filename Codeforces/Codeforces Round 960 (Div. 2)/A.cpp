#include "bits/stdc++.h"
using namespace std;

void solve()
{
    int n;
    cin >> n;
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        mp[x]++;
    }

    bool ans = false;
    for (auto &i : mp)
    {
        if (i.second & 1)
        {
            ans = true;
            break;
        }
    }

    cout << (ans ? "YES" : "NO") << "\n";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}