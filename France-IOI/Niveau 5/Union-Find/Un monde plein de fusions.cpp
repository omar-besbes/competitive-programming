#include "bits/stdc++.h"

using namespace std;

int n, r;
vector<int> parent, sizes;

int find_set(int v)
{
    if (v == parent[v])
        return v;
    else
        return parent[v] = find_set(parent[v]);
}

bool join_set(int x, int y)
{
    x = find_set(x);
    y = find_set(y);

    if (x != y)
    {
        if (sizes[x] < sizes[y])
            swap(x, y);
        parent[y] = parent[x];
        sizes[x] += sizes[y];
    }

    return x != y;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> r;
    parent.assign(n, 0);
    sizes.assign(n, 1);
    for (int i = 0; i < n; ++i)
    {
        parent[i] = i;
    }

    for (int i = 0; i < r; ++i)
    {
        int x, y;
        cin >> x >> y;
        if (join_set(x, y))
        {
            cout << x << " " << y << "\n";
        }
    }
}