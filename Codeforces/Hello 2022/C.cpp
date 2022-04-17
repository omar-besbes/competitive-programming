#include <bits/stdc++.h>

using namespace std;

int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//    cout.tie(nullptr);
//    freopen("name.in", "r", stdin);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w+", stdout);

    int t;
    cin >> t;
    while (t--) {
        int n, k, mini, maxi, sum = 0, nbSteps, last = n-1;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            sum += a[i];
        }
        sort(a, a+n);
        nbSteps = max(0, sum - k);
        mini = a[0];
        maxi = a[n-1];
        while (sum > k) {
            sum -= a[last] - mini;
        }
    }

    return 0;
}