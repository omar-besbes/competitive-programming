#include <iostream>
using namespace std;

int main()
{
    int nbCibles;
    cin >> nbCibles;
    int Cible[nbCibles];
    for (int C = 0; C < nbCibles; C++)
        cin >> Cible[C];

    int nbLots;
    cin >> nbLots;
    int Lot[nbLots];
    for (int L = 0; L < nbLots; L++)
        cin >> Lot[L];

    int L = 0;
    for (int C = 0; C < nbCibles; C++)
    {
        if (Cible[C] == Lot[L])
            cout << Lot[L] << " ";
        else
        {
            while (Cible[C] >= Lot[L] && L < nbLots)
                L++;
            L--;
            cout << Lot[L] << " ";
        }
    }
}