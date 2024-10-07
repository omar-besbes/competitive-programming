#include <iostream>
using namespace std;

int main() {
   int nbEmissions, maximum;
   cin >> nbEmissions >> maximum;
   int Duree[nbEmissions];
   for (int E = 0; E < nbEmissions; E++) cin >> Duree[E];

   int best = 0;
   int debut = 0, fin = 0;
   int actuel = 0;
   while (fin < nbEmissions) {
      actuel += Duree[fin];
      if (actuel > maximum) {
         if (best < fin - debut) best = fin - debut;
         while (debut <= fin && actuel > maximum) {
            actuel -= Duree[debut];
            debut++;
         }
         fin++;
      } else
         fin++;
   }

   if (best < fin - debut) best = fin - debut;
   cout << best;
}