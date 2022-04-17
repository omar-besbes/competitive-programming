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
        int n;
        cin >> n;
        string  s;
        cin >> s;
        if(n>2)
            cout <<  "NO\n";
        else if(n==2) {
            if(s == "10" || s == "01")
                cout << "YES\n";
            else cout <<  "NO\n";
        } else cout << "YES\n";

    }

    return 0;
}