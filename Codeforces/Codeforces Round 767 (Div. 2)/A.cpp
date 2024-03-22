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
    while(t--) {
        int n, k;
        cin >> n >> k;
        pair<int, int> a[n];
        for (int i = 0; i < n; ++i) {
            cin >> a[i].first;
        }
        for (int i = 0; i < n; ++i) {
            cin >> a[i].second;
        }
        sort(a, a+n);
        int index = 0;
        while (index < n && k >= a[index].first) {
            k += a[index].second;
            index++;
        }
        cout << k << '\n';
    }

    return 0;
}