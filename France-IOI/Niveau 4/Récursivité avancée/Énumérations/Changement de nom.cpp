#include <iostream>
using namespace std;

int puissance(int nombre, int exposant)
{
    int total = 1;
    while (exposant > 0)
    {
        total *= nombre;
        exposant--;
    }
    return total;
}

void Possibilite(char Lettres[], int nbL, int nbM, int current, char mot[])
{
    current++;

    if (current == nbM)
        for (int L = 0; L < nbL; L++)
        {
            mot[current - 1] = Lettres[L];
            for (int m = 0; m < nbM; m++)
                cout << mot[m];
            cout << "\n";
        }
    else
        for (int L = 0; L < nbL; L++)
        {
            mot[current - 1] = Lettres[L];
            Possibilite(Lettres, nbL, nbM, current, mot);
        }
}

int main()
{
    int nbL;
    cin >> nbL;
    char Lettres[nbL];
    for (int L = 0; L < nbL; L++)
        cin >> Lettres[L];
    int nbMot;
    cin >> nbMot;
    cout << puissance(nbL, nbMot) << endl;
    char Mot[nbMot] = {" "};
    Possibilite(Lettres, nbL, nbMot, 0, Mot);
}