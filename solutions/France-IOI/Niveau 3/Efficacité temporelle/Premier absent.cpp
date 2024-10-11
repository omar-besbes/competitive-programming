#include <iostream>
using namespace std;

int main() {
   int nbEleves, nbPresents;
   cin >> nbEleves >> nbPresents;

   bool Presents[250001] = {false};
   int premier = 1;
   for (int present = 1; present <= nbPresents; present++) {
      int eleve;
      cin >> eleve;
      if (eleve <= 250001) Presents[eleve - 1] = true;

      while (Presents[premier - 1]) premier++;
      if (premier > nbEleves) premier = -1;
      cout << premier << endl;
   }
}