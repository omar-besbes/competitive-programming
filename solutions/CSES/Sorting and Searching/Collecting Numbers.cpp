#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a)
        cin >> i;

    set<int> sequences;
    for (int i = 0; i < n; i++)
    {
        int curr = a[i];
        if (sequences.find(curr - 1) != sequences.end())
            sequences.erase(curr - 1), sequences.insert(curr);
        else
            sequences.insert(curr);
    }

    cout << sequences.size() << "\n";
}