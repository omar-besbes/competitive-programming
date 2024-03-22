#include "bits/stdc++.h"

using namespace std;

struct intervalle
{
    int debut, fin;
    int indiceAvantTri;
    int numSalle;
};
typedef struct intervalle interval;

bool compareIntervalle(interval &a, interval &b)
{
    if (a.debut == b.debut)
        return a.fin < b.fin;
    return a.debut < b.debut;
}

bool compareIndice(interval &a, interval &b)
{
    return a.indiceAvantTri < b.indiceAvantTri;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int nbS, nbR;
    cin >> nbS >> nbR;
    interval I[nbR];
    vector<interval> S[nbS];
    for (int i = 0; i < nbR; i++)
    {
        cin >> I[i].debut >> I[i].fin;
        I[i].indiceAvantTri = i;
    }
    sort(I, I + nbR, compareIntervalle);

    for (auto &i : I)
    {
        int s = 0;
        while (s < nbS)
        {
            if (S[s].empty())
            {
                i.numSalle = s + 1;
                S[s].push_back(i);
                break;
            }
            else if (S[s].back().fin <= i.debut)
            {
                i.numSalle = s + 1;
                S[s].push_back(i);
                break;
            }
            s++;
        }
        if (s >= nbS)
        {
            cout << "NON";
            return 0;
        }
    }
    sort(I, I + nbR, compareIndice);
    cout << "OUI" << '\n';
    for (auto i : I)
    {
        cout << i.numSalle << ' ';
    }

    return 0;
}