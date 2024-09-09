#include "bits/stdc++.h"

using namespace std;

int n, r;
vector<int> arr, seg;

void init(int index = 1, int l = 0, int r = n - 1)
{
    // cout << "init " << l << " " << r << "\n";
    if (l == r)
    {
        seg[index] = arr[l];
    }
    else
    {
        int m = (l + r) / 2;
        init(2 * index, l, m);
        init(2 * index + 1, m + 1, r);
        seg[index] = seg[2 * index] + seg[2 * index + 1];
    }
}

void update(int key, int index = 1, int l = 0, int r = n - 1)
{
    // cout << "update " << l << " " << r << " " << a[key] << "\n";
    if (key < l || key > r)
        return;
    if (l == r)
    {
        seg[index] = arr[key];
    }
    else
    {
        int m = (l + r) / 2;
        if (key <= m)
            update(key, 2 * index, l, m);
        else
            update(key, 2 * index + 1, m + 1, r);
        seg[index] = seg[2 * index] + seg[2 * index + 1];
    }
}

int get(pair<int, int> range, int index = 1, int l = 0, int r = n - 1)
{
    // cout << "get " << l << " " << r << " " << range.first << " " << range.second << "\n";
    if (range.first > range.second)
        return 0;
    if (range.first == l && range.second == r)
    {
        return seg[index];
    }
    else
    {
        int m = (l + r) / 2;
        int leftsum = get(make_pair(range.first, min(range.second, m)), 2 * index, l, m);
        int rightsum = get(make_pair(max(m + 1, range.first), range.second), 2 * index + 1, m + 1, r);
        return leftsum + rightsum;
    }
}

void print()
{
    for (int i = 1; i < 4 * n; i++)
        cout << seg[i] << " ";
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    seg.resize(4 * n);
    arr.resize(n);
    for (auto &i : arr)
        cin >> i;

    init();

    cin >> r;
    for (int i = 0; i < r; i++)
    {
        char type;
        cin >> type;
        if (type == 'M')
        {
            int key, value;
            cin >> key >> value;
            arr[key] = value;
            update(key);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            cout << get(make_pair(l, r)) << "\n";
        }
    }
}