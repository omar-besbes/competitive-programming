#include <bits/stdc++.h>
using namespace std;

template <typename T,typename U>
pair<T,U> operator+(const std::pair<T,U> &l,const std::pair<T,U> &r) {
    return {l.first+r.first,l.second+r.second};
}
template <typename T,typename U>
pair<T,U> operator-(const std::pair<T,U> &l,const std::pair<T,U> &r) {
    return {l.first - r.first, l.second - r.second};
}

int L, C, **G;
pair<int, int> arrivee, depart;
pair<pair<int, int>, char> Direction[4] = { {{0, 1}, 'E'},
                                            {{-1, 0}, 'N'},
                                            {{0, -1}, 'O'},
                                            {{1, 0}, 'S'} };

struct situation{
    pair<int, int> position;
    int deg;
    string  chemin;
};

bool sortDeLaGrille(struct situation &s) {
    if(s.position.first < 0 || s.position.second < 0 || s.position.first >= L || s.position.second >= C)
        return true;
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("input.txt.txt", "r", stdin);
    freopen("output.txt", "w+", stdout);

    cin >> L >> C;
    G = new int* [L];
    for (int i = 0; i < L; ++i) {
        string x;
        cin >> x;
        G[i] = new int [C];
        for (int j = 0; j < C; ++j) {
            if(x[j] - '#')
                G[i][j] = -1; // . = -1
            else G[i][j] = -2; // # = -2
        }
    }

    arrivee = {L-1, C-2};
    depart = {1, 0};
    struct situation actuelle = {depart, 0, ""};
    queue<struct situation> nextToMark;
    nextToMark.push(actuelle);
    G[1][0] = 0;

    while (!nextToMark.empty()) {
        actuelle = nextToMark.front();
        nextToMark.pop();
        if(actuelle.position == arrivee)
            break;
        for (auto i:Direction) {
            struct situation nextSituation = actuelle;
            nextSituation.position = nextSituation.position + i.first;
            nextSituation.deg++;
            nextSituation.chemin.push_back(i.second);
            if(sortDeLaGrille(nextSituation))
                continue;
            if(G[nextSituation.position.first][nextSituation.position.second] != -1)
                continue;
            G[nextSituation.position.first][nextSituation.position.second] = nextSituation.deg;
            nextToMark.push(nextSituation);
        }
    }

    cout << actuelle.chemin.size() << '\n';
    cout << actuelle.chemin;

    return 0;
}