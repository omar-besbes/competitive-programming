#include <bits/stdc++.h>
using namespace std;

int n, q, t, l;
vector<set<int>> e;
vector<vector<int>> up;
vector<int> in, out;

void buildAncestors(int v, int p, int d = 0)
{
    in[v] = ++t;
    up[v][0] = p;
    for (int i = 1; (1 << i) <= d; i++)
        up[v][i] = (up[up[v][i - 1]][i - 1]);

    for (int u : e[v])
        if (u != p)
            buildAncestors(u, v, d + 1);
    out[v] = ++t;
}

int msb(int n)
{
    return 31 - __builtin_clz(n);
}

int query(int x, int k)
{
    if (k == 0)
        return x;
    if (x == 1)
        return -1;

    int _msb = msb(k), l = up[x].size();
    if (_msb < l)
        return query(up[x][_msb], k - (1 << _msb));
    else
        return -1;
}

bool is_ancestor(int c, int p)
{
    return in[c] >= in[p] && out[c] <= out[p];
}

int lca(int a, int b)
{
    if (is_ancestor(a, b))
        return b;
    if (is_ancestor(b, a))
        return a;
    for (auto i = l; i >= 0; i--)
        if (up[a][i] != -1 && !is_ancestor(b, up[a][i]))
            a = up[a][i];
    return up[a][0];
}

void solve()
{
    cin >> n >> q;
    l = ceil(log2(n));
    up.resize(n + 1, vector<int>(l + 1, -1));
    e.resize(n + 1);
    t = 0;
    in.resize(n + 1);
    out.resize(n + 1);
    for (int i = 2; i <= n; i++)
    {
        int p;
        cin >> p;
        e[p].insert(i);
    }

    buildAncestors(1, 1);

    for (int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b;

        cout << lca(a, b) << "\n";
    }
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