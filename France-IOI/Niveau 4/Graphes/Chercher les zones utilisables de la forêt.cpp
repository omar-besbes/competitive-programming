#include <bits/stdc++.h>
using namespace std;

int zone(vector<int> *N, vector<bool> &visited, int pos)
{
    if (visited[pos])
        return 0;
    visited[pos] = true;
    int nbNparZone = 1;
    for (auto i : N[pos])
    {
        nbNparZone += zone(N, visited, i);
    }
    return nbNparZone;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int nbN, nbS, nbZone = 0, maxZone, z;
    cin >> nbN >> nbS;
    vector<int> N[nbN];
    vector<bool> V(nbN);
    for (int i = 0; i < nbS; ++i)
    {
        int n1, n2, l;
        cin >> n1 >> n2 >> l;
        N[n1 - 1].push_back(n2 - 1);
        N[n2 - 1].push_back(n1 - 1);
    }

    z = zone(N, V, 0);
    maxZone = z;
    if (z)
        nbZone++;
    for (int i = 1; i < nbN; ++i)
    {
        z = zone(N, V, i);
        maxZone = max(z, maxZone);
        if (z)
            nbZone++;
    }

    cout << nbZone << " " << maxZone;

    return 0;
}