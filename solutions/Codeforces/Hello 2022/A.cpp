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
        int n, k;
        cin >> n >> k;
        int rooks = ceil((double) n/2);
        if(rooks < k) {
            cout <<"-1\n";
            continue;
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if(i == j && j%2 == 0 && k-- > 0)
                    cout << "R";
                else cout << ".";
            }
            cout << "\n";
        }
    }

    return 0;
}