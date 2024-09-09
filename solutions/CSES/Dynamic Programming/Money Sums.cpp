#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a)
        cin >> i;

    vector<set<int>> dp(n);
    dp[0] = {a[0]};

    for (int i = 1; i < n; i++)
    {
        dp[i] = dp[i - 1];
        for (auto &j : dp[i - 1])
            dp[i].insert(a[i] + j), dp[i].insert(a[i]);
    }

    cout << dp[n - 1].size() << "\n";
    for (auto &i : dp[n - 1])
        cout << i << " ";
    cout << "\n";
}
