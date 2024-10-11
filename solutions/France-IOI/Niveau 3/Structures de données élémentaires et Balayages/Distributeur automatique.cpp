#include <iostream>
using namespace std;

int main() {
   int nboperation;
   cin >> nboperation;
   int nombre, date;
   int compteurbas = 0;
   int compteurhaut = 0;
   int P[1000];
   for (int l = 0; l < nboperation; l++) {
      cin >> nombre >> date;
      if (date == 0)
         compteurbas -= nombre;
      else {
         for (int p = 0; p < nombre; p++) P[(p + compteurhaut) % 1000] = date;
         compteurhaut += nombre;
      }
   }

   int result = P[compteurbas % 1000];
   for (int p = compteurbas; p < compteurhaut; p++)
      if (P[p % 1000] < result && P[p % 1000] != 0) result = P[p % 1000];

   cout << result << endl;
}