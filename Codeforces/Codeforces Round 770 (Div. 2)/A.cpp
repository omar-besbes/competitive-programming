#include <bits/stdc++.h>

using namespace std;

bool isPalindrome(string &s) {
    auto d = s.begin(), f = s.end()-1;
    while (f >= d && f[0] == d[0]) {
        f--;
        d++;
    }
    if(f[0] != d[0])
        return false;
    return true;
}

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
        string  s;
        cin >> s;
        if(k == 0)
            cout << "1\n";
        else {
            if (isPalindrome(s))
                cout << "1\n";
            else cout << "2\n";
        }
    }

    return 0;
}