#include "bits/stdc++.h"
using namespace std;

void solve()
{
    int n;
    cin >> n;
    int a[n], mex = 0;
    set<int> used;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        int nextMex = mex;
        int x = nextMex - a[i];
        if (x >= 0 && x <= n - 1 && x != mex && used.find(x) == used.end())
        {
            used.insert(x);
        }
        else
        {
            x = mex;
            used.insert(x);
            while (used.find(nextMex) != used.end())
                nextMex++;
        }
        mex = nextMex;
        cout << x << " ";
    }
    cout << "\n";
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