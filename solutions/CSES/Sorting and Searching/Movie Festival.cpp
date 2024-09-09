#include <bits/stdc++.h>
using namespace std;

#define ii pair<int, int>

int main()
{
    int n;
    cin >> n;
    vector<ii> m(n);
    for (auto &i : m)
        cin >> i.first >> i.second;

    sort(m.begin(), m.end(), [](auto x, auto y)
         { return x.second == y.second ? x.first < y.first : x.second < y.second; });

    int ans = 0, curr = 1;
    for (auto next = m.begin(); next != m.end(); next++)
    {
        if (next->first < curr)
            continue;
        curr = next->second;
        ans++;
    }

    cout << ans << "\n";
}