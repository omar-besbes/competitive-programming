#include "bits/stdc++.h"
using namespace std;

void solve()
{
    string s, o;
    cin >> o;
    int idx, n = s.length();
    cin >> idx;
    idx--;

    for (int i = 0; i < o.length(); i++)
    {
        if (i != idx - 1 && i != idx + 1)
            s.push_back(o[i]);
    }

    sort(s.begin(), s.end());

    if (idx - 1 >= 0)
        s.insert(s.begin() + idx - 1, o[idx - 1]);
    if (idx + 1 <= o.length() - 1)
        s.insert(s.begin() + idx + 1, o[idx + 1]);

    cout << s << "\n";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}
