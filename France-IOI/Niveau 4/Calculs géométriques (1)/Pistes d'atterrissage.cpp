#include "bits/stdc++.h"

using namespace std;

int prodVectoriel(const pair<int, int> &composantes_A, const pair<int, int> &composantes_B)
{
    return composantes_A.first * composantes_B.second - composantes_A.second * composantes_B.first;
}

int prodScalaire(const pair<int, int> &composantes_A, const pair<int, int> &composantes_B)
{
    return (composantes_A.first * composantes_B.first) + (composantes_A.second * composantes_B.second);
}

int distance_PtoP(pair<int, int> &A, pair<int, int> &B)
{
    return sqrt(pow((A.first - B.first), 2) + pow((A.second - B.second), 2));
}

pair<int, int> composantes(pair<int, int> &X, pair<int, int> &Y)
{
    pair<int, int> composante;
    composante.first = Y.first - X.first;
    composante.second = Y.second - X.second;
    return composante;
}

double distance_PtoL(pair<int, int> &P, pair<int, int> &A, pair<int, int> &B)
{
    // H projeté de p sur AB
    double distanceOrienteeAH = prodScalaire(composantes(A, B), composantes(A, P));
    double AB = distance_PtoP(A, B);
    distanceOrienteeAH /= (AB);
    if (distanceOrienteeAH > AB)
        return distance_PtoP(B, P);
    else if (distanceOrienteeAH < 0)
        return distance_PtoP(A, P);
    else
        return abs(prodVectoriel(composantes(A, B), composantes(A, P)) / AB);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    pair<int, int> tourControle;
    int N, indexMini = 0;
    cin >> tourControle.first >> tourControle.second >> N;
    pair<pair<int, int>, pair<int, int>> piste[N];
    double D[N];
    for (int i = 0; i < N; ++i)
    {
        cin >> piste[i].first.first >> piste[i].first.second;
        cin >> piste[i].second.first >> piste[i].second.second;
        D[i] = distance_PtoL(tourControle, piste[i].first, piste[i].second);
        if (D[i] < D[indexMini])
            indexMini = i;
    }
    cout << piste[indexMini].first.first << ' ' << piste[indexMini].first.second << ' ';
    cout << piste[indexMini].second.first << ' ' << piste[indexMini].second.second;

    return 0;
}