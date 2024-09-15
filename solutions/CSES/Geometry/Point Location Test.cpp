#include "bits/stdc++.h"
using namespace std;
#define pii pair<int, int>
#define pll pair<long long, long long>
#define ll long long

const double epsilon = 1e-5;

void solve()
{
    pll p[3];
    for (int i = 0; i < 3; i++)
        cin >> p[i].first >> p[i].second;

    pll v = make_pair(p[1].first - p[0].first, p[1].second - p[0].second);
    pll u = make_pair(p[2].first - p[0].first, p[2].second - p[0].second);

    ll cross = v.first * u.second - v.second * u.first;

    cout << (cross == 0 ? "TOUCH" : (cross < 0 ? "RIGHT" : "LEFT")) << "\n";
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