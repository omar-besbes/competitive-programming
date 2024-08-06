#include "bits/stdc++.h"
using namespace std;

const int RULER_LENGTH = 999;

int ask(int l, int r)
{
    int ans;
    cout << "? " << l << " " << r << "\n"
         << flush;
    cin >> ans;
    return ans;
}

void solve()
{
    int start = 0, end = RULER_LENGTH;
    while (start < end)
    {
        int l = start + (end - start) / 3;
        int r = end - (end - start) / 3;
        int ans = ask(l, r);

        if (ans == l * r)
            start = r + 1;
        else if (ans == l * (r + 1))
            start = l + 1, end = r;
        else
            end = l;
    }

    cout << "! " << end << "\n"
         << flush;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}