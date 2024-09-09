#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("input.txt", "r", stdin);

    int t;
    cin >> t;
    while(t--) {
        long long x, y, u, v;
        cin >> u >> v;
        x = u*u;
        y = -v*v;
        cout << x << ' ' << y << '\n';
    }

    return 0;
}