#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    set<long long> visited{1};
    while (visited.find(n) == visited.end())
        cout << n << " ", visited.insert(n), n = (n & 1 ? 3 * n + 1 : n / 2);
    cout << 1 << "\n";
}