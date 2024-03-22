#include <iostream>
using namespace std;

int main()
{
    int nbElements;
    cin >> nbElements;
    int Tableau[nbElements];
    for (int E = 0; E < nbElements; E++)
        cin >> Tableau[E];

    int maximum = 0;
    int actuel = 0;
    for (int E = 0; E < nbElements; E++)
        if (Tableau[E] <= 0)
        {
            if (maximum < actuel)
                maximum = actuel;

            if (actuel + Tableau[E] > 0)
                actuel += Tableau[E];
            else
                actuel = 0;
        }
        else
            actuel += Tableau[E];

    if (maximum < actuel)
        maximum = actuel;
    cout << maximum;
}