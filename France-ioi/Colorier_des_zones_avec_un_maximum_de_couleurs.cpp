#include <bits/stdc++.h>
using namespace std;

template <typename T,typename U>
pair<T,U> operator+(const std::pair<T,U> &l,const std::pair<T,U> &r) {
    return {l.first+r.first,l.second+r.second};
}

int N, M;
int couleur;
pair<int, int> Direction[4] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };

void explore(bool **G, pair<int, int> pos) {
    if(pos.first < 0 || pos.first >= N || pos.second < 0 || pos.second >= M)
        return;
    if(G[pos.first][pos.second])
        return;
    G[pos.first][pos.second] = true;
    for (auto i : Direction) {
        explore(G, pos + i);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //freopen("input.txt.txt", "r", stdin);

    cin >> N >> M;
    couleur = 0;
    bool* G[N];
    for (int i = 0; i < N; ++i) {
        string x;
        G[i] = new bool[M];
        cin >> x;
        for (int j = 0; j < M; ++j) {
            if(x[j] - '#')
                G[i][j] = false;
            else G[i][j] = true;
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if(!G[i][j]) {
                explore(G, {i, j});
                couleur++;
            }
        }
    }

    cout << couleur;

    return 0;
}