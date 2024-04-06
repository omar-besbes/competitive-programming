#include "bits/stdc++.h"
using namespace std;

class Solution
{
protected:
    int n;

public:
    virtual void solve() = 0;
};

class SegmentTreeSolution : public Solution
{
private:
    vector<int> v, u;
    vector<long long> seg_v, seg_u;

    void build(int cur = 1, int l = 0, int r = -1)
    {
        if (r == -1)
            r = n - 1;
        if (l == r)
        {
            seg_v[cur] = v[l];
            seg_u[cur] = u[l];
        }
        else
        {
            int m = (l + r) / 2;
            build(cur * 2, l, m);
            build(cur * 2 + 1, m + 1, r);
            seg_v[cur] = seg_v[cur * 2] + seg_v[cur * 2 + 1];
            seg_u[cur] = seg_u[cur * 2] + seg_u[cur * 2 + 1];
        }
    }

    long long query(int type, pair<int, int> range, int cur = 1, int l = 0, int r = -1)
    {
        if (r == -1)
            r = n - 1;
        if (range.first > range.second)
            return 0;
        if (range.first > r || range.second < l)
            return 0;
        if (range.first == l && range.second == r)
            return (type == 1 ? seg_v[cur] : seg_u[cur]);

        int m = (l + r) / 2;
        auto left = query(type, make_pair(range.first, min(range.second, m)), cur * 2, l, m);
        auto right = query(type, make_pair(max(range.first, m + 1), range.second), cur * 2 + 1, m + 1, r);
        return left + right;
    }

public:
    SegmentTreeSolution()
    {
        cin >> n;
        v.resize(n), u.resize(n);
        seg_v.resize(4 * n), seg_u.resize(4 * n);
        for (int i = 0; i < n; i++)
            cin >> v[i], u[i] = v[i];
        sort(u.begin(), u.end());
        build();
    }

    void solve()
    {
        int m;
        cin >> m;
        for (int i = 0; i < m; i++)
        {
            int type;
            cin >> type;
            int l, r;
            cin >> l >> r;
            cout << query(type, make_pair(l - 1, r - 1)) << "\n";
        }
    }
};

class PrefixArraySolution : public Solution
{
private:
    vector<long long> v, u;

public:
    PrefixArraySolution()
    {
        cin >> n;
        v.resize(n + 1), u.resize(n + 1);
        for (int i = 0; i < n; ++i)
        {
            cin >> v[i + 1];
            u[i + 1] = v[i + 1];
        }

        sort(u.begin(), u.end());
        for (int i = 1; i < n + 1; ++i)
        {
            u[i] += u[i - 1];
            v[i] += v[i - 1];
        }
    }

    void solve()
    {
        int m;
        cin >> m;
        for (int i = 0; i < m; ++i)
        {
            int type, l, r;
            cin >> type >> l >> r;
            if (type == 1)
                cout << v[r] - v[l - 1] << "\n";
            else
                cout << u[r] - u[l - 1] << "\n";
        }
    }
};

class SqrtDecompositionSolution : public Solution
{
private:
    int blk_len;
    vector<int> v, u;
    vector<long long> blk_v, blk_u;

    long long query(int type, int l, int r)
    {
        long long ans = 0;
        vector<int> &a = (type == 1 ? v : u);
        vector<long long> &blk_a = (type == 1 ? blk_v : blk_u);
        int first_blk = l / blk_len, last_blk = r / blk_len;

        if (first_blk == last_blk)
        {
            for (int i = l; i <= r; i++)
                ans += a[i];
        }
        else
        {
            for (int i = l; i < (first_blk + 1) * blk_len; i++)
                ans += a[i];
            for (int i = first_blk + 1; i < last_blk; i++)
                ans += blk_a[i];
            for (int i = last_blk * blk_len; i <= r; i++)
                ans += a[i];
        }

        return ans;
    }

public:
    SqrtDecompositionSolution()
    {
        cin >> n;
        blk_len = ceil(sqrt(n));
        v.resize(n), u.resize(n);
        blk_v.assign(blk_len, 0), blk_u.assign(blk_len, 0);
        for (int i = 0; i < n; i++)
            cin >> v[i], u[i] = v[i];
        sort(u.begin(), u.end());
        for (int i = 0; i < n; i++)
            blk_v[i / blk_len] += v[i], blk_u[i / blk_len] += u[i];
    }

    void solve()
    {
        int m;
        cin >> m;
        for (int i = 0; i < m; i++)
        {
            int type;
            cin >> type;
            int l, r;
            cin >> l >> r;
            cout << query(type, l - 1, r - 1) << "\n";
        }
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    Solution *solution = new SqrtDecompositionSolution();
    solution->solve();
}