#include "bits/stdc++.h"

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;

        int pref[n];
        pref[0] = s[0] == '0' ? 1 : 0;
        for (int i = 1; i < n; i++)
        {
            pref[i] = pref[i - 1] + (s[i] == '0' ? 1 : 0);
        }

        vector<int> res;
        if (n - pref[n - 1] >= (n + 1) / 2)
            res.push_back(0);
        for (int i = 1; i <= n; i++)
        {
            int left = pref[i - 1];
            int right = (n - i) - (pref[n - 1] - pref[i - 1]);
            if (left >= (i + 1) / 2 && right >= (n - i + 1) / 2)
            {
                res.push_back(i);
            }
        }

        pair<int, int> mini = make_pair(res[0], abs(n - 2 * res[0]));
        for (auto &i : res)
        {
            if (abs(n - 2 * i) < mini.second)
                mini = make_pair(i, abs(n - 2 * i));
        }

        cout << mini.first << "\n";
    }
}