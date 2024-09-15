#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int mod = 1e9 + 7;

ll binpow(ll a, ll b, ll mod)
{
    if (b == 0)
        return 1;
    auto tmp = binpow(a, b / 2, mod);
    if (b & 1)
        return (a * tmp % mod) * tmp % mod;
    else
        return tmp * tmp % mod;
}

void solve()
{
    ll a, b, c;
    cin >> a >> b >> c;
    cout << binpow(a, binpow(b, c, mod - 1), mod) << "\n";
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