#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int choose(string tab[], int N, int K) {
    int sum = 0;
    for(int i=0; i < N; i++)
        sum += choose(tab+i+K+1, N-K-i-1, K);
    return sum;
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
        int N, K;
        cin >> N >> K;
        string tab[N];
        for(int i=0; i<N; i++)
            cin >> tab[i];
        cout << choose(tab, N, K);
    }


    return 0;
}