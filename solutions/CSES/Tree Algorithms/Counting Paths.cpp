#include <bits/stdc++.h>
using namespace std;

int n, q;
vector<set<int>> e;
vector<pair<int, int>> euler, seg;
vector<int> first, last, ans, pa;

void dfs(int v, int p, int d = 0)
{
    euler.push_back({d, v});
    first[v] = euler.size() - 1;
    pa[v] = p;
    for (auto c : e[v])
        if (c != p)
        {
            dfs(c, v, d + 1);
            euler.push_back({d, v});
            last[v] = euler.size() - 1;
        }
}

void dfs2(int v)
{
    for (auto c : e[v])
        if (c != pa[v])
            dfs2(c), ans[v] += ans[c];
}

void build(int v = 1, int l = 0, int r = euler.size() - 1)
{
    if (l == r)
        seg[v] = euler[l];
    else
    {
        int m = (l + r) / 2;
        build(2 * v, l, m);
        build(2 * v + 1, m + 1, r);
        seg[v] = min(seg[2 * v], seg[2 * v + 1]);
    }
}

pair<int, int> lca(int a, int b, int v = 1, int l = 0, int r = euler.size() - 1)
{
    if (a > r || b < l)
        return {n + 1, -1};
    if (a == l && b == r)
        return seg[v];

    int m = (l + r) / 2;
    auto ansl = lca(a, min(b, m), 2 * v, l, m);
    auto ansr = lca(max(a, m + 1), b, 2 * v + 1, m + 1, r);
    return min(ansl, ansr);
}

void update(int a, int b)
{
    int _lca = lca(min(first[a], first[b]), max(first[a], first[b])).second;
    ans[_lca]--;
    ans[a]++, ans[b]++;
    if (_lca != 1)
        ans[pa[_lca]]--;
}

void solve()
{
    cin >> n >> q;
    e.resize(n + 1);
    first.resize(n + 1);
    last.resize(n + 1);
    ans.resize(n + 1);
    pa.resize(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        e[a].insert(b);
        e[b].insert(a);
    }

    dfs(1, 1);
    seg.resize(4 * (euler.size() + 1));
    build();

    for (int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b;
        update(a, b);
    }

    dfs2(1);

    for (int i = 0; i < n; i++)
        cout << ans[i + 1] << " ";
    cout << "\n";
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