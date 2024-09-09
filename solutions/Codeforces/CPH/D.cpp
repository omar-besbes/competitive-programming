#include <bits/stdc++.h>

using namespace std;

int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//    cout.tie(nullptr);
//    freopen("name.in", "r", stdin);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w+", stdout);

    string s;
    cin >> s;
    int cu = s.length() - 1, op = 0;
    while(cu > 0) {
        while(s[cu] == '0') {
            cu--; op++;
        }
        if(cu == 0)
            break;

        while (cu >= 0 && s[cu] == '1') {
            cu--; op++;
        }
        op++;
        if(cu < 0)
            break;
        s[cu] = '1';
    }

    cout << op;

    return 0;
}