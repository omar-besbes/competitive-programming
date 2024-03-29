#include "bits/stdc++.h"

using namespace std;

set<long long> s;
int a[31] = {10, 11, 100, 101, 110, 111, 1000, 1001, 1010, 1011, 1100, 1101,
           1110, 1111, 10000, 10001, 10010, 10011, 10100, 10101, 10110, 10111,
           11000, 11001, 11010, 11011, 11100, 11101, 11110, 11111, 100000};

void dfs(long long x)
{
    if (x <= 100000)
    {
        s.insert(x);
        for (int i = 0; i < 31; i++)
            dfs(x * a[i]);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    dfs(1);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        if (s.find(n) != s.end())
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}