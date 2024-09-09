#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int A, B, C, D, N, M;
    cin >> A >> B >> C >> D >> N >> M;
    vector<int> visited(100000 + 1, false);
    queue<int> nextToOperate;
    nextToOperate.push(N);

    while (!nextToOperate.empty())
    {
        N = nextToOperate.front();
        nextToOperate.pop();

        // reach solution
        if (N == M)
        {
            cout << 1;
            return 0;
        }

        // not in range
        if (N > 100000 || N < 0 || visited[N])
            continue;

        visited[N] = true;
        nextToOperate.push(N + A);
        nextToOperate.push(N - B);
        nextToOperate.push(N * C);
        if (D && N % D == 0)
            nextToOperate.push(N / D);
    }

    cout << 0;

    return 0;
}