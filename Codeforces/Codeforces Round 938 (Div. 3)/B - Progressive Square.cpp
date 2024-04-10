#include "bits/stdc++.h"
using namespace std;

void solve()
{
    int n, c, d;
    cin >> n >> c >> d;
    if (c > d)
        swap(c, d);
    vector<int> a(n * n), b(n * n);
    for (int i = 0; i < n * n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            b[n * i + j] = a[0] + i * c + j * d;
    sort(b.begin(), b.end());

    bool test = true;
    for (int i = 0; test && i < n * n; i++)
        if (a[i] != b[i])
            test = false;
    cout << (test ? "YES\n" : "NO\n");
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