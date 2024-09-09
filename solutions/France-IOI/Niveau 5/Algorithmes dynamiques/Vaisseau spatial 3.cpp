#include "bits/stdc++.h"
using namespace std;

#define N 20000
#define M 500

int n, m, p;
int after[M], curr[M];

int getMax(int j)
{
    int res = curr[j];
    if (j > 0 && curr[j - 1] > res)
        res = curr[j - 1];
    if (j < m - 1 && curr[j + 1] > res)
        res = curr[j + 1];
    return res;
}

void print()
{
    for (int j = 0; j < m; j++)
        cout << curr[j] << " ";
    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> p;
    fill_n(curr, m, 0);
        fill_n(after, m, 0);
    for (int i = 0; i < n - 1; i++)
    {
        int index, value;
        cin >> index >> value;
        for (int j = 0; j < m; j++)
            after[j] = getMax(j);
        after[index] += value;
        for (int j = 0; j < m; j++)
            curr[j] = after[j];
    }

    cout << getMax(p) << "\n";

    return 0;
}