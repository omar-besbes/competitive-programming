#include <bits/stdc++.h>

using namespace std;

int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//    cout.tie(nullptr);
//    freopen("name.in", "r", stdin);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w+", stdout);

    int n;
    cin >> n;
    string  s;
    cin >> s;
    for (int i = 0; i < n-1; ++i) {
        if(s[i] == 'B') {
            if(s[i + 1] == 'B') {
                s[i] = 'A';
                s[i + 1] = 'D';
            } else if(s[i + 1] == 'A') {
                s[i] = 'A';
                s[i + 1] = 'B';
            }
        }
    }

    for (auto item:s) {
        if(item != 'D')
            cout << item;
    }
    cout << "\n";

    return 0;
}