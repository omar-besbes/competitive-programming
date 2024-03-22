#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int nbDistributeurs, nbOperations, iD, qte, annee;
    cin >> nbDistributeurs >> nbOperations;
    vector<pair<int, int>> Distributeur[nbDistributeurs];

    for (int i = 0; i < nbOperations; ++i)
    {
        cin >> iD >> qte >> annee;
        if (qte > 0)
            if (!Distributeur[iD - 1].empty() && Distributeur[iD - 1].back().first == annee)
                Distributeur[iD - 1].back().second += qte;
            else
                Distributeur[iD - 1].emplace_back(annee, qte);
        else
            while (qte && !Distributeur[iD - 1].empty())
                if (-qte >= Distributeur[iD - 1].front().second)
                {
                    qte += Distributeur[iD - 1].front().second;
                    Distributeur[iD - 1].erase(Distributeur[iD - 1].begin());
                }
                else
                {
                    Distributeur[iD - 1].front().second += qte;
                    qte = 0;
                }
    }

    for (int i = 0; i < nbDistributeurs; ++i)
    {
        if (Distributeur[i].empty())
            cout << 0 << '\n';
        else
        {
            int mini = Distributeur[i].front().first;
            Distributeur[i].erase(Distributeur[i].begin());
            while (!Distributeur[i].empty())
            {
                mini = min(mini, Distributeur[i].front().first);
                Distributeur[i].erase(Distributeur[i].begin());
            }
            cout << mini << '\n';
        }
    }

    return 0;
}