#include "bits/stdc++.h"

#define _L 40 + 1
#define _C 40 + 1

using namespace std;
const int D[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

char grid[_L][_C];
vector<pair<int, int>> ball;
int L, C, N;

void print() {
   for (int i = 0; i < L; i++) {
      for (int j = 0; j < C; j++) cout << grid[i][j] << " ";
      cout << "\n";
   }
}

void move(int dir, int B) {
   int l = ball[B].first, c = ball[B].second;
   if (l == -1 || c == -1) return;
   int nextL = l + D[dir][0], nextC = c + D[dir][1];
   if (nextL < 0 || nextC < 0 || nextL >= L || nextC >= C) return;

   grid[l][c] = '.';

   // cout << "ball at:" << l << " " << c << "\n";

   // falls in hole
   if (grid[nextL][nextC] == 'O') {
      // cout << "ball falls\n";
      ball[B] = make_pair(-1, -1);
   }

   // moves forward in the specified direction
   else if (grid[nextL][nextC] == '.') {
      // cout << "ball moves to:" << nextL << " " << nextC << "\n";
      ball[B] = make_pair(nextL, nextC);
      grid[nextL][nextC] = 'x';
      move(dir, B);
   }

   // must move the ball in front of it before
   else if (grid[nextL][nextC] == 'x') {
      // cout << "another ball ahead\n";
      for (unsigned int i = 0; i < ball.size(); i++) {
         if (i != B && ball[i].first == nextL && ball[i].second == nextC) {
            move(dir, i);
            // the ball in front has fallen in a hole, so must this ball
            if (ball[i].second == -1) {
               // cout << "ball ahead has fallen\n";
               ball[B] = make_pair(-1, -1);
            }
            // the ball is somewhere in the same direction, so this ball must be
            // behind it
            else {
               // cout << "ball ahead at:" << ball[i].first << " " <<
               // ball[i].second << "\n";
               nextL = ball[i].first - D[dir][0];
               nextC = ball[i].second - D[dir][1];

               ball[B] = make_pair(nextL, nextC);
               grid[nextL][nextC] = 'x';
            }

            return;
         }
      }
   }

   // stuck at its place due to wall
   else if (grid[nextL][nextC] == '#') {
      grid[l][c] = 'x';
   }
}

int main() {
   cin >> L >> C;
   char dir;
   for (int i = 0; i < L; i++)
      for (int j = 0; j < C; j++) {
         cin >> grid[i][j];
         if (grid[i][j] == 'x') ball.emplace_back(i, j);
      }

   cin >> N;
   for (int i = 0; i < N; i++) {
      cin >> dir;
      switch (dir) {
         case 'N':
            dir = 0;
            break;
         case 'E':
            dir = 1;
            break;
         case 'S':
            dir = 2;
            break;
         case 'O':
            dir = 3;
            break;
      }

      for (unsigned int i = 0; i < ball.size(); i++) move(dir, i);

      // print();
   }

   cout << count_if(ball.begin(), ball.end(), [](pair<int, int> &b) {
      return b.first != -1 && b.second != -1;
   });

   return 0;
}