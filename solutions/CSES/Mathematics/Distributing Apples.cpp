#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mod = 1e9 + 7;

vector<int> fact(1e7 + 1, 1);

int binpow(int a, int b)
{
    if (b == 0)
        return 1;
    auto tmp = binpow(a, b / 2);
    if (b & 1)
        return (tmp * tmp % mod) * a % mod;
    else
        return (tmp * tmp % mod);
}

int inv(int a)
{
    return binpow(a, mod - 2);
}

int ncr(int n, int k)
{
    if (k > n)
        return 0;
    return (fact[n] * inv(fact[k]) % mod) * inv(fact[n - k]) % mod;
}

void genFactorial()
{
    int n = fact.size();
    for (int i = 1; i < n; i++)
        fact[i] = fact[i - 1] * i % mod;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    int ans = 0;
    cout << ncr(m + n - 1, m) << "\n";
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    genFactorial();

    int t = 1;
    // cin >> t;
    while (t--)
        solve();
}