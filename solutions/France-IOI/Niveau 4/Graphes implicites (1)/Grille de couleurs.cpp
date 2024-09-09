#include <bits/stdc++.h>
using namespace std;

template <typename T, typename U>
pair<T, U> operator+(const std::pair<T, U> &l, const std::pair<T, U> &r)
{
    return {l.first + r.first, l.second + r.second};
}

pair<int, int> Direction[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int H, L;

bool explore(string *G, bool **visited, pair<int, int> posN, pair<int, int> posB)
{
    if (posB.first < 0 || posB.first >= H || posB.second < 0 || posB.second >= L)
        return false;
    if (posN.first < 0 || posN.first >= H || posN.second < 0 || posN.second >= L)
        return false;
    if (G[posN.first][posN.second] != G[posB.first][posB.second])
        return false;
    if (visited[posN.first * L + posN.second][posB.first * L + posB.second])
        return false;
    visited[posN.first * L + posN.second][posB.first * L + posB.second] = true;
    // cout << "B : " << posB.first << " " << posB.second << "\n";
    // cout << "N : " << posN.first << " " << posN.second << "\n";
    if (posN.first == H - 1 && posN.second == L - 1 && posB.first == 0 && posB.second == 0)
        return true;
    for (auto i : Direction)
    {
        for (auto j : Direction)
        {
            if (explore(G, visited, posN + i, posB + j))
                return true;
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> L >> H;
    string grille[H];
    bool **visited;
    visited = new bool *[H * L];
    for (int i = 0; i < H; ++i)
    {
        cin >> grille[i];
    }
    for (int i = 0; i < H * L; ++i)
    {
        visited[i] = new bool[H * L];
        for (int j = 0; j < H * L; ++j)
        {
            visited[i][j] = false;
        }
    }

    if (explore(grille, visited, {0, 0}, {H - 1, L - 1}))
        cout << 1;
    else
        cout << 0;

    return 0;
}