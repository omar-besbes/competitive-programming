#include "bits/stdc++.h"
using namespace std;

#define M 201

vector<long long> dp;

long long find(int a, int b, int c, int d)
{
    if (a < 0 || b < 0 || c < 0)
        return 0;

    long long idx = M * M * a + M * b + c;
    if (dp[idx] != -1)
        return dp[idx];

    dp[idx] = (((1 * (a & 1)) ^ (2 * (b & 1)) ^ (3 * (c & 1))) == 0) ? 1 : 0;

    long long ans = 0;

    ans = max(ans, find(a - 1, b, c, d));
    ans = max(ans, find(a, b - 1, c, d));
    ans = max(ans, find(a, b, c - 1, d));

    return dp[idx] += ans;
}

void solve()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    auto ans = find(a, b, c, d);
    cout << ans + d / 2 << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    dp.assign(M * M * M, -1);
    dp[0] = 0;

    int t;
    cin >> t;
    while (t--)
        solve();
}