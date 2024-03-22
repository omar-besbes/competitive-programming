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
        long long a[n], sum = 0;
        for (auto item : a) {
            cin >> item;
            sum = sum|item;
        }
        cout << sum << "\n";
    }

    return 0;
}