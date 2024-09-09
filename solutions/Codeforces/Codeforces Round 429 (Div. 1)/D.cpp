#include "bits/stdc++.h"
using namespace std;

#define MAX_K 5

int n, q, blk_len;

struct Query
{
    int l, r, k, index;
    bool operator<(Query other)
    {
        int this_blk = l / blk_len, other_blk = other.l / blk_len;
        return this_blk == other_blk ? r < other.r : this_blk < other_blk;
    }
};

vector<int> arr;
vector<Query> queries;

vector<int> mo()
{
    vector<int> ans(q);
    sort(queries.begin(), queries.end());

    int l = 0, r = -1;
    map<int, int> cur;
    for (Query q : queries)
    {
        while (l > q.l)
        {
            l--;
            cur[arr[l]]++;
        }
        while (r < q.r)
        {
            r++;
            cur[arr[r]]++;
        }
        while (l < q.l)
        {
            cur[arr[l]]--;
            l++;
        }
        while (r > q.r)
        {
            cur[arr[r]]--;
            r--;
        }
        ans[q.index] = n + 1;
        int limit = (r - l + 1) / q.k;
        for (auto &i : cur)
            if (i.second > limit)
                ans[q.index] = min(ans[q.index], i.first);
        if (ans[q.index] == n + 1)
            ans[q.index] = -1;
    }
    return ans;
}

int main()
{
    cin >> n >> q;
    blk_len = ceil(sqrt(n));
    arr.resize(n);
    queries.resize(q);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = 0; i < q; i++)
    {
        int l, r, k;
        cin >> l >> r >> k;
        queries[i].l = l - 1;
        queries[i].r = r - 1;
        queries[i].index = i;
        queries[i].k = k;
    }

    auto ans = mo();
    for (auto &i : ans)
        cout << i << "\n";
}