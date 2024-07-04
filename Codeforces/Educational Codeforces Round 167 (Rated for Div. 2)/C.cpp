#include "bits/stdc++.h"
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto &i : a)
        cin >> i;
    for (auto &j : b)
        cin >> j;

    pair<int, int> rat = {0, 0};
    int nbPositiveForBoth = 0, nbNegativeForBoth = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == b[i])
        {
            nbPositiveForBoth += (a[i] == 1 ? 1 : 0);
            nbNegativeForBoth += (a[i] == -1 ? 1 : 0);
        }
        else if (a[i] > b[i])
        {
            rat.first += a[i];
        }
        else
        {
            rat.second += b[i];
        }
    }

    int toAdd = min(nbPositiveForBoth, abs(rat.first - rat.second));
    if (rat.first > rat.second)
        rat.second += toAdd;
    else
        rat.first += toAdd;
    nbPositiveForBoth -= toAdd;

    if (nbPositiveForBoth > nbNegativeForBoth)
    {
        nbPositiveForBoth -= nbNegativeForBoth;
        int toAdd = min(nbPositiveForBoth, abs(rat.first - rat.second));
        if (rat.first > rat.second)
            rat.second += toAdd;
        else
            rat.first += toAdd;
        nbPositiveForBoth -= toAdd;
        rat.first += nbPositiveForBoth / 2;
        rat.second += nbPositiveForBoth - nbPositiveForBoth / 2;
    }
    else
    {
        nbNegativeForBoth -= nbPositiveForBoth;
        int toSubstract = min(nbNegativeForBoth, abs(rat.first - rat.second));
        if (rat.first > rat.second)
            rat.first -= toSubstract;
        else
            rat.second -= toSubstract;
        nbNegativeForBoth -= toSubstract;
        rat.first -= nbNegativeForBoth / 2;
        rat.second -= nbNegativeForBoth - nbNegativeForBoth / 2;
    }

    cout << min(rat.first, rat.second) << "\n";
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