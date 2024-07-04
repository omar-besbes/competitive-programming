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
    vector<long long> pref;

public:
    SegmentTreeSolution()
    {
        pref.assign(n + 1, 0);
        for (int i = 1; i < n + 1; i++)
            pref[i] = pref[i - 1] + a[i - 1];
    }

    void solve()
    {
        for (int i = 0; i < q; i++)
        {
            int l, r;
            cin >> l >> r;
            cout << pref[r] - pref[l - 1] << "\n";
        }
    }
};

class FenwickTreeSolution : public Solution
{
private:
    vector<long long> bit;

    int lsb(int i)
    {
        return i & -i;
    }

    int parent(int i)
    {
        return i + lsb(i);
    }

    long long pref(int i)
    {
        return bit[i] + (i ? pref(i - lsb(i)) : 0);
    }

public:
    FenwickTreeSolution()
    {
        bit.assign(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            bit[i] += a[i - 1];
            bit[parent(i)] += bit[i];
        }
    }

    void solve()
    {
        for (int i = 0; i < q; i++)
        {
            int l, r;
            cin >> l >> r;
            cout << pref(r) - pref(l - 1) << "\n";
        }
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    Solution *sol = new FenwickTreeSolution();
    sol->solve();

    return 0;
}
