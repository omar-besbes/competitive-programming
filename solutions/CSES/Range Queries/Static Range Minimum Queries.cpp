#include <bits/stdc++.h>
using namespace std;

class Solution
{
protected:
    int n, q;
    vector<int> a;

    Solution()
    {
        cin >> n >> q;
        a.assign(n, 0);
        for (auto &i : a)
            cin >> i;
    }

public:
    virtual void solve() = 0;
};

class SegmentTreeSolution : public Solution
{
private:
    vector<int> seg;

    void build(int id, int l, int r)
    {
        if (l == r)
            seg[id] = a[l];
        else
        {
            int m = (l + r) / 2;
            build(id * 2, l, m);
            build(id * 2 + 1, m + 1, r);
            seg[id] = min(seg[2 * id], seg[2 * id + 1]);
        }
    }

    int query(pair<int, int> range, int id, int l, int r)
    {
        if (range.first > range.second)
            return INT_MAX;
        if (range.first > r || range.second < l)
            return INT_MAX;
        if (range.first == l && range.second == r)
            return seg[id];
        int m = (l + r) / 2;
        int left = query(make_pair(range.first, min(range.second, m)), 2 * id, l, m);
        int right = query(make_pair(max(range.first, m + 1), range.second), 2 * id + 1, m + 1, r);
        return min(left, right);
    }

public:
    SegmentTreeSolution()
    {
        seg.assign(4 * n, 0);
        build(1, 0, n - 1);
    }

    void solve()
    {
        for (int i = 0; i < q; i++)
        {
            int l, r;
            cin >> l >> r;
            cout << query(make_pair(l - 1, r - 1), 1, 0, n - 1) << "\n";
        }
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    Solution *sol = new SegmentTreeSolution();
    sol->solve();

    return 0;
}
