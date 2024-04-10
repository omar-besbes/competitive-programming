#include "bits/stdc++.h"
using namespace std;

#define WALL '*'
#define EMPTY '.'

int n, m, k;
vector<vector<char>> g;
vector<int> dsu, ans;

int d[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int parent(int v)
{
    return v == dsu[v] ? v : dsu[v] = parent(dsu[v]);
}

void merge(int a, int b)
{
    if (a < 0 || b < 0)
        return;
    a = parent(a);
    b = parent(b);
    if (a == b)
        return;
    dsu[a] = b;
}

int dfs(int p, int x, int y)
{
    int idx = parent(m * x + y);
    if (x < 0 || x >= n || y < 0 || y >= m)
        return 0;
    if (g[x][y] == WALL)
        return 1;
    // cout << "entering " << x << " " << y << "\n";
    if (ans[idx] != -1)
        return ans[idx];

    int r = 0;
    ans[idx] = 0;
    merge(idx, p);
    for (auto [dx, dy] : d)
        r += dfs(idx, x + dx, y + dy);
    // cout << "for " << x << " " << y << " " << r << "\n";

    return ans[idx] += r;
}

void solve()
{
    cin >> n >> m >> k;
    g.assign(n, vector<char>(m));
    ans.assign(n * m, -1);
    dsu.resize(n * m);
    for (int i = 0; i < n * m; i++)
        dsu[i] = i;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> g[i][j];

    for (int i = 0; i < k; i++)
    {
        int x, y;
        cin >> x >> y;
        cout << dfs(-1, x - 1, y - 1) << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}