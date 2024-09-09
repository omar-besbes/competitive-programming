#include <bits/stdc++.h>
using namespace std;

int n, m;

int main()
{
    cin >> n >> m;
    int curr, last;
    multiset<int> t;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        t.insert(-x);
    }
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        auto k = t.lower_bound(-x);
        if (k == t.end())
            cout << -1 << "\n";
        else
        {
            cout << -*k << "\n";
            t.erase(k);
        }
    }
}