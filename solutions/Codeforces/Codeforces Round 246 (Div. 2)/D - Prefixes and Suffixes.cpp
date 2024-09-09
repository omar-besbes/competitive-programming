#include "bits/stdc++.h"
using namespace std;

int main()
{
    string s;
    cin >> s;
    int n = s.length();

    vector<int> prefix(n);
    map<int, int> occ;
    for (int i = 1; i < n; i++)
    {
        int j = prefix[i - 1];
        while (j > 0 && s[j] != s[i])
            j = prefix[j - 1];
        prefix[i] = s[i] == s[j] ? j + 1 : 0;
        occ[prefix[i]]++;
    }

    occ[n] = 1;
    for (int i = n; i > 0; i--)
        occ[prefix[i - 1]] += occ[i];

    /*
    for (int i = 0; i < n; i++)
    {
        cout << setw(2) << s[i] << " ";
    }
    cout << "\n";
    for (int i = 0; i < n; i++)
    {
        cout << setw(2) << prefix[i] << " ";
    }
    cout << "\n";
    */

    vector<pair<int, int>> ans;
    for (int j = n; j > 0; j = prefix[j - 1])
    {
        ans.emplace_back(j, occ[j]);
    }

    cout << ans.size() << "\n";
    for (int i = ans.size() - 1; i >= 0; i--)
    {
        cout << ans[i].first << " " << ans[i].second << "\n";
    }
}