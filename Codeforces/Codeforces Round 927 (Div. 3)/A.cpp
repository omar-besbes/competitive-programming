#include "bits/stdc++.h"
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;
    for (int i = 0; i < n;)
    {
        ans += (s[i] == '@' ? 1 : 0);
        if (i + 1 < n && s[i + 1] != '*')
            i++;
        else if (i + 2 < n && s[i + 2] != '*')
            i += 2;
        else
            break;
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