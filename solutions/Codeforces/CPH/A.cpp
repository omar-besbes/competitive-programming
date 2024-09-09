#include <bits/stdc++.h>

using namespace std;

int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//    cout.tie(nullptr);
//    freopen("name.in", "r", stdin);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w+", stdout);

    int m[5], w[5];
    for (int i = 0; i < 5; ++i) {
        cin >> m[i];
    }

    for (int i = 0; i < 5; ++i) {
        cin >> w[i];
    }
    int hs, hu;
    cin >> hs >> hu;

    double s = hs*100 - hu*50;
    for (int i = 0; i < 5; ++i) {
        double x = 500*(i+1);
        s += max(0.3*x, (1-(double)m[i]/250)*x - 50*w[i]);
    }

    cout << s;

    return 0;
}