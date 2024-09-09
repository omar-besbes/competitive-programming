#include <bits/stdc++.h>

using namespace std;

int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//    cout.tie(nullptr);
//    freopen("name.in", "r", stdin);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w+", stdout);

    int n, a, b, r;
    cin >> n >> a >> b;
    if(b < 0)
        b += 100*n;
    r = (a+b)%n;
    if(r == 0) r = n;
    cout << r;

    return 0;
}