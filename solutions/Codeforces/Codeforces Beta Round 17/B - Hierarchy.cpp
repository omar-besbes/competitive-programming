#include "bits/stdc++.h"
using namespace std;

int n, m;
vector<int> dsu, q;
vector<tuple<int, int, int>> edges;

bool has_parent(int v)
{
    return v != dsu[v];
}

int parent(int v)
{
    return v == dsu[v] ? v : dsu[v] = parent(dsu[v]);
}

bool merge(int a, int b)
{
    if (has_parent(b))
        return false;
    a = parent(a);
    b = parent(b);
    if (a == b)
        return false;
    dsu[b] = a;
    return true;
}

void solve()
{
    cin >> n;
    dsu.resize(n);
    q.resize(n);
    for (int i = 0; i < n; i++)
        dsu[i] = i, cin >> q[i];
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edges.emplace_back(c, a - 1, b - 1);
    }
    sort(edges.begin(), edges.end());

    long long ans = 0, merge_ops = 0;
    for (int i = 0; i < m; i++)
    {
        auto [c, a, b] = edges[i];
        if (merge(a, b))
            ans += c, merge_ops++;
    }

    cout << (merge_ops == n - 1 ? ans : -1) << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}