#include <bits/stdc++.h>
using namespace std;

template <typename T, typename U>
pair<T, U> operator+(const std::pair<T, U> &l, const std::pair<T, U> &r) {
   return {l.first + r.first, l.second + r.second};
}

template <typename T, typename U>
pair<T, U> operator-(const std::pair<T, U> &l, const std::pair<T, U> &r) {
   return {l.first - r.first, l.second - r.second};
}

int L, C, **G;
pair<int, int> arrivee, depart;
pair<pair<int, int>, char> Direction[4] = {
    {{0, 1}, 'E'}, {{-1, 0}, 'N'}, {{0, -1}, 'O'}, {{1, 0}, 'S'}};

bool sortDeLaGrille(pair<int, int> &p) {
   if (p.first < 0 || p.second < 0 || p.first >= L || p.second >= C)
      return true;
   return false;
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);

   cin >> L >> C;
   G = new int *[L];
   for (int i = 0; i < L; ++i) {
      string x;
      cin >> x;
      G[i] = new int[C];
      for (int j = 0; j < C; ++j) {
         if (x[j] - '#')
            G[i][j] = -1;  // . = -1
         else
            G[i][j] = -2;  // # = -2
      }
   }

   arrivee = {L - 1, C - 2};
   depart = {1, 0};
   pair<pair<int, int>, string> actuelle;
   queue<pair<pair<int, int>, string>> nextToMark;
   nextToMark.push(make_pair(depart, ""));
   G[1][0] = 0;

   while (!nextToMark.empty()) {
      actuelle = nextToMark.front();
      nextToMark.pop();

      if (actuelle.first == arrivee) break;

      for (auto i : Direction) {
         pair<int, int> nextP = actuelle.first;
         nextP = nextP + i.first;

         if (sortDeLaGrille(nextP)) continue;

         if (G[nextP.first][nextP.second] != -1) continue;

         G[nextP.first][nextP.second] =
             G[actuelle.first.first][actuelle.first.second] + 1;
         nextToMark.push(make_pair(nextP, actuelle.second + i.second));
      }
   }

   cout << actuelle.second.size() << '\n';
   cout << actuelle.second;

   return 0;
}