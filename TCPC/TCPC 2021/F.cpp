#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("xorsum.in", "r", stdin);
    freopen("input.txt.txt", "r", stdin);
    /*
    int t;
    cin >> t;
    while(t--) {

    }
    */
    int N, Q;
    cin >> N >> Q;
    int a[N];
    for(int i=0; i<N; i++)
        cin >> a[i];
    for(int q=0; q<Q; q++){
        int i, j, X, Y;
        cin >> i >> j >> X >> Y;
        i--;
        j--;
        int Rang[Y - X + 1];
        for(int h=0; h<Y-X+1; h++){
            int b = 0;
            Rang[h] = 0;
            while(b+i<=j) {
                if (a[b + i] == X + h) Rang[h]++;
                b++;
            }
        }
        int affiche = Rang[0];
        for(int k=1; k<Y-X+1; k++)
            affiche = affiche ^ Rang[k];
        cout << affiche << '\n';
    }
}
