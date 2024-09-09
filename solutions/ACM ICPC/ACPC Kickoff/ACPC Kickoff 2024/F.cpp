#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n, vector<int>(m));
    for (auto &i : g)
    {
        for (auto &j : i)
        {
            cin >> j;
        }
    }

    int maxi = 0;
    for (int i = 0; i < n; i++)
    {
        int k = i, j = 0, tmp = 0;
        while(k >= 0 && j < m) tmp += g[k--][j++];
        maxi = max(maxi, tmp);
    }

    for (int j = 0; j < m; j++)
    {
        int i = n-1, k = j, tmp = 0;
        while(i >= 0 && k < m) tmp += g[i--][k++];
        maxi = max(maxi, tmp);
    }
    
    cout << maxi << "\n";   
}
