#include "bits/stdc++.h"

using namespace std;

int n, m;
vector<vector<int>> adj;
vector<int> dp;

int nb_paths(int cu)
{
    if (dp[cu] == -1)
    {
        dp[cu] = 0;
        for (const auto &item : adj[cu])
        {
            dp[cu] += nb_paths(item);
        }
    }
    return dp[cu];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    adj.assign(n, {});
    dp.assign(n, -1);

    for (int i = 0; i < m; ++i)
    {
        int x, y;
        cin >> x >> y;
        adj[y - 1].emplace_back(x - 1);
    }

    dp[0] = 1;
    cout << nb_paths(n - 1) << "\n";
}