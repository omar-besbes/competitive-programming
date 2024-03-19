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

int L, C, N, **G;
pair<int, int> Direction[4] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };

void affiche() {
    for (int i = 0; i < L; ++i) {
        for (int j = 0; j < C; ++j) {
            cout.fill(' ');
            int wi = 3;
            if(G[i][j] == -2)
                cout << setw(wi) << '#';
            else if(G[i][j] == -1)
                cout << setw(wi) << '.';
            else cout << setw(wi) << G[i][j];
        }
        cout << '\n';
    }
    cout << '\n';
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
    cin >> N;
    vector<int> nbPanneaux(N);
    queue<pair<pair<int, int>, int>> nextToMark;
    nextToMark.push({{L - 1, C - 2}, 0});

    while (!nextToMark.empty()) {
        pair<int, int> current = nextToMark.front().first;
        int deg = nextToMark.front().second;
        nextToMark.pop();
        if(current.first < 0 || current.second < 0 || current.first >= L || current.second >= C)
            continue;
        if(G[current.first][current.second] != -1)
            continue;
        if(deg > N)
            continue;
        G[current.first][current.second] = deg;
        if(deg) nbPanneaux[deg-1]++;
        for (auto i:Direction) {
            nextToMark.push({current + i, deg + 1});
        }
    }

    affiche();

    for (int i = 0; i < N; ++i) {
        cout << nbPanneaux[i] << " ";
    }

    return 0;
}