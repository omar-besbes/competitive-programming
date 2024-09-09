#include <bits/stdc++.h>

using namespace std;

int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//    cout.tie(nullptr);
//    freopen("name.in", "r", stdin);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w+", stdout);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[2*n];
        for (auto &i : a) {
            cin >> i;
        }
        int maxi = a[0] + a[2*n-1];
        for (int i = 1; i < n; ++i) {
            maxi = max(maxi, a[i] + a[2*n - 1 - i]);
        }
        cout << maxi << '\n';
    }

    return 0;
}