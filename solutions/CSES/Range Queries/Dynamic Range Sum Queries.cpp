#include <bits/stdc++.h>

using namespace std;

int n, q;
vector<long long> *a, *seg;

void build(int index = 1, int seg_l = 0, int seg_r = n - 1)
{
    if (seg_l == seg_r)
    {
        (*seg)[index] = (*a)[seg_l];
    }
    else
    {
        int seg_m = (seg_l + seg_r) / 2;
        build(2 * index, seg_l, seg_m);
        build(2 * index + 1, seg_m + 1, seg_r);
        (*seg)[index] = (*seg)[2 * index] + (*seg)[2 * index + 1];
    }
}

long long sum(int l, int r, int index = 1, int seg_l = 0, int seg_r = n - 1)
{
    if (l > r)
        return 0;

    if (l == seg_l && r == seg_r)
    {
        return (*seg)[index];
    }

    int seg_m = (seg_l + seg_r) / 2;
    return sum(l, min(seg_m, r), 2 * index, seg_l, seg_m) +
           sum(max(l, seg_m + 1), r, 2 * index + 1, seg_m + 1, seg_r);
}

void update(int pos, int val, int index = 1, int seg_l = 0, int seg_r = n - 1)
{
    if (seg_l == seg_r)
    {
        (*seg)[index] = val;
    }
    else
    {
        int seg_m = (seg_l + seg_r) / 2;
        if (pos <= seg_m)
        {
            update(pos, val, index * 2, seg_l, seg_m);
        }
        else
        {
            update(pos, val, index * 2 + 1, seg_m + 1, seg_r);
        }
        (*seg)[index] = (*seg)[2 * index] + (*seg)[2 * index + 1];
    }
}

int main()
{
    //    ios::sync_with_stdio(false);
    //    cin.tie(nullptr);
    //    cout.tie(nullptr);

    cin >> n >> q;
    a = new vector<long long>(n);
    seg = new vector<long long>(4 * n);

    for (int i = 0; i < n; ++i)
    {
        cin >> (*a)[i];
    }

    build();

    int x, y, k, u, type;
    while (q--)
    {
        cin >> type;
        if (type == 2)
        {
            cin >> x >> y;
            cout << sum(x - 1, y - 1) << "\n";
        }
        else
        {
            cin >> k >> u;
            (*a)[k - 1] = u;
            update(k - 1, u);
        }
    }
}
