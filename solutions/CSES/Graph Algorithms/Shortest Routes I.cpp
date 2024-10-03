#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<ll, int> edge;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<ll> d(n, LONG_LONG_MAX);
    vector<map<int, ll>> e(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        if (e[u - 1].count(v - 1))
            e[u - 1][v - 1] = min(w, e[u - 1][v - 1]);
        else
            e[u - 1][v - 1] = w;
    }

    priority_queue<edge, vector<edge>, greater<edge>> q;
    q.push({0, 0});
    d[0] = 0;

    while (!q.empty())
    {
        auto [newd, u] = q.top();
        q.pop();

        if (newd > d[u])
            continue;

        d[u] = newd;
        for (auto [v, w] : e[u])
            if (d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                q.push({d[v], v});
            }
    }

    for (int i = 0; i < n; i++)
        cout << d[i] << " ";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--)
        solve();
}