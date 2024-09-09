#include <bits/stdc++.h>

using namespace std;

int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//    cout.tie(nullptr);
//    freopen("name.in", "r", stdin);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w+", stdout);

    int n, x, closestMultiple2 = 0, maximumSteps = 15, steps = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        closestMultiple2 = 1;
        while ((1 << closestMultiple2) < x) closestMultiple2++;
        steps = (1 << closestMultiple2) - x + ceil(log2( (double)32768 / (1 << closestMultiple2)));
        cout << min(maximumSteps, steps) << '\n';
    }

    return 0;
}