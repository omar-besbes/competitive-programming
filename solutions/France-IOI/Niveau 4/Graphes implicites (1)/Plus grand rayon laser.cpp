#include "bits/stdc++.h"
using namespace std;
template <typename T, typename U>
pair<T, U> operator+(const pair<T, U> &a, const pair<T, U> &b) {
   return {a.first + b.first, a.second + b.second};
}

int nbL, nbC, maxLongueur;
const pair<pair<int, int>, char> Direction[4] = {
    {{1, 0}, 'S'}, {{-1, 0}, 'N'}, {{0, 1}, 'E'}, {{0, -1}, 'O'}};
string **G;

bool sortDeLaGrille(pair<int, int> &pos) {
   if (pos.first < 0 || pos.second < 0 || pos.first >= nbL || pos.second >= nbC)
      return true;
   return false;
}

pair<pair<int, int>, char> Orienter(pair<pair<int, int>, char> &D, char M) {
   switch (M) {
      case '/':
         if (D.second == Direction[0].second) return Direction[3];  // S -> O
         if (D.second == Direction[1].second) return Direction[2];  // N -> E
         if (D.second == Direction[2].second) return Direction[1];  // E -> N
         if (D.second == Direction[3].second) return Direction[0];  // O -> S
         break;
      case 92:
         if (D.second == Direction[0].second) return Direction[2];  // S -> E
         if (D.second == Direction[1].second) return Direction[3];  // N -> O
         if (D.second == Direction[2].second) return Direction[0];  // E -> S
         if (D.second == Direction[3].second) return Direction[1];  // O -> N
         break;
      default:
         break;
   }
   return D;
}

int explore(pair<int, int> pos, pair<pair<int, int>, char> D) {
   if (sortDeLaGrille(pos)) return 0;
   for (auto i : G[pos.first][pos.second])
      if (i == D.second) return 0;
   int longueur = 1;
   G[pos.first][pos.second].push_back(D.second);
   if (G[pos.first][pos.second][0] == '.')
      longueur += explore(pos + D.first, D);
   else {
      D = Orienter(D, G[pos.first][pos.second][0]);
      longueur += explore(pos + D.first, D);
   }
   G[pos.first][pos.second].pop_back();
   return longueur;
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);
   freopen("input.txt.txt", "r", stdin);
   freopen("output.txt", "w+", stdout);

   cin >> nbL >> nbC;
   G = new string *[nbL];
   for (int i = 0; i < nbL; ++i) {
      G[i] = new string[nbC];
      for (int j = 0; j < nbC; ++j) {
         char temp;
         cin >> temp;
         G[i][j] = temp;
      }
   }
   maxLongueur = 0;

   for (int i = 0; i < nbL; ++i)
      for (int j = 0; j < nbC; ++j)
         for (const auto &k : Direction)
            maxLongueur = max(explore({i, j}, k), maxLongueur);
   cout << maxLongueur;
   return 0;
}