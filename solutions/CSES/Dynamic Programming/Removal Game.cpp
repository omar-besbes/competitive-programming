#include "bits/stdc++.h"
using namespace std;
#define ll long long

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<ll> a(n), pref(n + 1);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        pref[i + 1] = pref[i] + a[i];
    }

    vector<vector<pair<ll, ll>>> dp(n, vector<pair<ll, ll>>(n, make_pair(-1, -1)));
    for (int i = 0; i < n; i++)
        dp[i][i] = make_pair(a[i], 0);

    for (int end = 1; end < n; end++)
    {
        for (int start = end - 1; start >= 0; start--)
        {
            dp[start][end].first = max(a[end] + dp[start][end - 1].second, a[start] + dp[start + 1][end].second);
            dp[start][end].second = pref[end + 1] - pref[start] - dp[start][end].first;
        }
    }

    cout << dp[0][n - 1].first << "\n";
}
