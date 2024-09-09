#include "bits/stdc++.h"
using namespace std;

void solve()
{
    int n;
    cin >> n;
    long long ans;
    cin >> ans;
    for(int i=1; i<n; i++) {
        long long curr; cin >> curr;
        ans = (ans / curr + 1) * curr;
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