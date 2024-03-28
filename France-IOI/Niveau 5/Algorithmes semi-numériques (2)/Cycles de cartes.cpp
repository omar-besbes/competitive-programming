#include "bits/stdc++.h"
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a)
        cin >> i;

    vector<vector<int>> c;
    vector<bool> used(n);
    for (int i = 0; i < n; i++)
    {
        if (used[i])
            continue;
        used[i] = true;
        c.push_back(vector<int>(1, a[i]));
        int j = i;
        while (a[j] != i + 1)
        {
            j = a[j] - 1;
            c.back().push_back(a[j]);
            used[j] = true;
        }
    }

    cout << c.size() << "\n";
    for (auto &i : c)
    {
        for (auto &j : i)
            cout << j << " ";
        cout << "\n";
    }
}