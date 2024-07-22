#include "bits/stdc++.h"
using namespace std;

void solve()
{
    int n;
    cin >> n;
    char trump;
    cin >> trump;

    map<char, set<int>> mp;
    mp['C'] = set<int>();
    mp['D'] = set<int>();
    mp['H'] = set<int>();
    mp['S'] = set<int>();

    for (int i = 0; i < 2 * n; i++)
    {
        string s;
        cin >> s;
        mp[s[1]].insert(s[0] - '0');
    }

    int imp = 0;
    for (auto [k, v] : mp)
        imp += (k != trump ? v.size() & 1 : 0);
    if (imp > mp[trump].size() || imp & 1 ^ mp[trump].size() & 1)
        cout << "IMPOSSIBLE" << "\n";
    else
    {
        for (auto [cls, values] : mp)
        {
            if (cls == trump)
                continue;
            if (values.size() & 1)
            {
                cout << *values.begin() << cls << " " << *mp[trump].begin() << trump << "\n";
                mp[trump].erase(*mp[trump].begin());
                values.erase(*values.begin());
            }

            bool pair = true;
            for (auto i : values)
            {
                if (pair)
                    cout << i << cls << " ";
                else
                    cout << i << cls << "\n";
                pair = !pair;
            }
        }

        bool pair = true;
        for (auto i : mp[trump])
        {
            if (pair)
                cout << i << trump << " ";
            else
                cout << i << trump << "\n";
            pair = !pair;
        }
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