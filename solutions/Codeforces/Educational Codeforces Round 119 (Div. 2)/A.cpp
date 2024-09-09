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
        string string1;
        cin >> string1;
        int n = string1.length();
        if(std::count(string1.begin(), string1.end(), 'N') == 1)
            cout << "NO\n";
        else cout << "YES\n";
    }

    return 0;
}