#include "bits/stdc++.h"
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    string ans = "";
    long long curr = 0;
    for (auto i : s)
        curr += i - '0';

    long long overflow = 0;
    for (int i = n - 1; i >= 0; curr -= s[i] - '0', i--)
    {
        char toAdd = '0' + ((curr + overflow) % 10LL);
        overflow = (curr + overflow) / 10LL;
        ans += toAdd;
    }

    // considering that overflow is a single digit
    ans += to_string(overflow);

    reverse(ans.begin(), ans.end());

    int idx = 0;
    while (ans[idx] == '0' && idx < ans.length() - 1)
        idx++;

    cout << ans.substr(idx) << "\n";
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