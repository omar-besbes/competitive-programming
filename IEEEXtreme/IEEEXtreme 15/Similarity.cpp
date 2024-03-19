#include <bits/stdc++.h>
using namespace std;

void rotation(char **g, int R, int C) {
    char Ng[R][C];
    for(int i=0; i<R; i++)
        for(int j=0; j<C; j++)
                Ng[i][j] = g[C-j-1][i];
    for(int i=0; i<R; i++)
        for(int j=0; j<C; j++)
            g[i][j] = Ng[i][j];
}

void flipV(char **g, int R, int C) {
    char Ng[R][C];
    for(int i=0; i<R; i++)
        for(int j=0; j<C; j++)
            Ng[i][j] = g[i][C-j-1];
    for(int i=0; i<R; i++)
        for(int j=0; j<C; j++)
            g[i][j] = Ng[i][j];
}

void flipH(char **g, int R, int C) {
    char Ng[R][C];
    for(int i=0; i<R; i++)
        for(int j=0; j<C; j++)
            Ng[i][j] = g[R-1-i][j];
    for(int i=0; i<R; i++)
        for(int j=0; j<C; j++)
            g[i][j] = Ng[i][j];
}



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("pack.in", "r", stdin);
    freopen("input.txt.txt", "r", stdin);

    int t;
    cin >> t;
    while(t--) {
        int R, C;
        cin >> R >> C;
        char grille[R][C];
        for(int i=0; i<R; i++)
            cin >> grille[i];



    }

    return 0;
}

