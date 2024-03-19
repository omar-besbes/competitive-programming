#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("input.txt.txt", "r", stdin);

    int A, B, C, D, N, M;
    cin >> A >> B >> C >> D >> N >> M;
    queue<int> nextToOperate;
    nextToOperate.push(N);

    while(!nextToOperate.empty()) {
        N = nextToOperate.front();
        nextToOperate.pop();
        if(N == M) {
            cout << 1;
            return 0;
        }
        if(N > 100000 || N < 0)
            continue;
        nextToOperate.push(N + A);
        nextToOperate.push(N - B);
        nextToOperate.push(N * C);
        if(N%D == 0) nextToOperate.push(N / D);
    }
    cout << 0;

    return 0;
}