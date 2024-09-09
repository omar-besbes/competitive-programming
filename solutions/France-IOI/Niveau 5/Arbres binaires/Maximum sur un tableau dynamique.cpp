#include "bits/stdc++.h"

using namespace std;

int n, h, r;
vector<int> seg;

void update(int index, int value, int v = 1, int seg_l = 0, int seg_r = n - 1)
{
    if (index > seg_r || index < seg_l)
        return;

    if (seg_l != seg_r)
    {
        int seg_m = (seg_l + seg_r) / 2;
        if (index <= seg_m)
            update(index, value, 2 * v, seg_l, seg_m);
        else
            update(index, value, 2 * v + 1, seg_m + 1, seg_r);
        seg[v] = max(seg[2 * v], seg[2 * v + 1]);
    }
    else
    {
        seg[v] = value;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> h >> r;
    n = 1 << h;
    seg.assign(4 * n, 0);

    for (int i = 0; i < r; ++i)
    {
        int index, value;
        cin >> index >> value;
        update(index, value);
        cout << seg[1] << "\n";
    }
}