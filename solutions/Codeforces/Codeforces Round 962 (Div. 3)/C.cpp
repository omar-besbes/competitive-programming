#include "bits/stdc++.h"
using namespace std;

vector<vector<int>> prea, preb;

void solve()
{
    int n, q;
    cin >> n >> q;

    string a, b;
    cin >> a >> b;

    prea.clear(), preb.clear();
    prea.push_back(vector<int>(26)), preb.push_back(vector<int>(26));

    for (int i = 0; i < n; i++)
    {
        prea.push_back(prea.back());
        preb.push_back(preb.back());

        prea.back()[a[i] - 'a']++;
        preb.back()[b[i] - 'a']++;
    }

    for (int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;
        l--;

        auto get_diff = [](vector<int> a, vector<int> b)
        {
            for (int k = 0; k < 26; k++)
            {
                int v = b[k];
                a[k] -= v;
            }
            return a;
        };

        auto mpa = get_diff(prea[r], prea[l]);
        auto mpb = get_diff(preb[r], preb[l]);

        int ans = 0;
        for (int k = 0; k < 26; k++)
        {
            int v = mpa[k];
            ans += max(v - mpb[k], 0);
        }

        cout << ans << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        solve();
}