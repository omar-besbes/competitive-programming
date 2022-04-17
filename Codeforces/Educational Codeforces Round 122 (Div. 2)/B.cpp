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
        string s;
        cin >> s;
        int nZ = 0, nO = 0;
        for (auto i:s) {
            if(i == '0') nZ++;
            if(i == '1') nO++;
        }
        if(nZ == nO)
            cout << nZ - 1 << "\n";
        else {
            cout << min(nZ, nO) << '\n';
        }
    }

    return 0;
}