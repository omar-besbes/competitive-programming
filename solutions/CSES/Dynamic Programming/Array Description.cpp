#include "bits/stdc++.h"
using namespace std;

const int mod = 1e9 + 7;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto &i : a)
        cin >> i;

    vector<vector<int>> dp(n, vector<int>(m + 1, 0));

    if (a[0])
    {
        dp[0][a[0]] = 1;
    }
    else
    {
        for (int i = 1; i <= m; i++)
            dp[0][i] = 1;
    }

    for (int i = 1; i < n; i++)
    {
        auto cur = a[i];
        if (cur)
        {
            for (auto k : {cur - 1, cur, cur + 1})
                if (k >= 1 && k <= m)
                    dp[i][cur] += dp[i - 1][k], dp[i][cur] %= mod;
        }
        else
        {
            for (int j = 1; j <= m; j++)
                for (auto k : {j - 1, j, j + 1})
                    if (k >= 1 && k <= m)
                        dp[i][j] += dp[i - 1][k], dp[i][j] %= mod;
        }
    }

    auto res = 0;
    for (int i = 1; i <= m; i++)
        res += dp[n - 1][i], res %= mod;

    cout << res << "\n";
}