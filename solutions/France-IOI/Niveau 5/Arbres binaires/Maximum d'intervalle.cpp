#include "bits/stdc++.h"

using namespace std;

int n, q;
vector<int> seg, arr;

void build(int v = 1, int l = 0, int r = n - 1)
{
    if (l == r)
    {
        seg[v] = arr[l];
    }
    else
    {
        int m = (l + r) / 2;
        build(2 * v, l, m);
        build(2 * v + 1, m + 1, r);
        seg[v] = max(seg[2 * v], seg[2 * v + 1]);
    }
}

int get(int l, int r, int v = 1, int seg_l = 0, int seg_r = n - 1)
{
    if (l > r)
        return -1;
    if (l == seg_l && r == seg_r)
    {
        return seg[v];
    }
    else
    {
        int seg_m = (seg_l + seg_r) / 2;
        return max(get(l, min(r, seg_m), 2 * v, seg_l, seg_m), get(max(l, seg_m + 1), r, 2 * v + 1, seg_m + 1, seg_r));
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    seg.assign(4 * n, 0);
    arr.assign(n, 0);
    for (auto &item : arr)
    {
        cin >> item;
    }

    build();

    cin >> q;
    for (int i = 0; i < q; ++i)
    {
        int l, r;
        cin >> l >> r;
        cout << get(l - 1, r - 1) << "\n";
    }
}