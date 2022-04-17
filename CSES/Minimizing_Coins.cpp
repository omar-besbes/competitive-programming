#include <bits/stdc++.h>
#define MAX_MONEY 1000000
#define MAX_COINS 100
using namespace std;

int n, dp[MAX_MONEY+1];
vector<int> values;
int nbCoins(int x) {
    if(dp[x] != -1) return dp[x];
    for (auto i = values.begin(); x >= *i && i < values.end(); i++) {
        if (nbCoins(x - *i) == -1) continue;
        if (dp[x] == -1)
            dp[x] = dp[x - *i] + 1;
        else
            dp[x] = min(dp[x], dp[x - *i] + 1);
//        cout << x << '\n';
    }
    return dp[x];
}

int main()
{
//    freopen("challenge.in", "r", stdin);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int x;
    cin >> n >> x;
    dp[0] = 0;
    for (int & i : dp)
        i = -1;
    for (int i = 0; i < n; ++i) {
        int y;
        cin >> y;
        dp[y] = 1;
        values.push_back(y);
    }

    sort(values.begin(), values.end());
    nbCoins(x);
    cout << dp[x];

    return 0;
}