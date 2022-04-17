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
        int n, liked = 0;
        cin >> n;
        vector<int> p(n), q(n);
        for (auto &i:p) {
            cin >> i;
        }
        string s;
        cin >> s;
        liked = count(s.begin(), s.end(), [](char x) {return x != '0';});
        int debut = 1, fin = n;
        for (int i = 0; i < n; ++i) {
            if(s[i]-'0') {
                q[i] = fin--;
            } else {
                q[i] = debut++;
            }
        }
        for (int i = 0; i < n; ++i) {
            if(s[i]-'0') {
                if(p[i] > n-liked)
                    for (int j=0; j<n; j++) {
                        if(q[j] == p[i]) {
                            swap(q[i], q[j]);
                            break;
                        }
                    }
            } else {
                if(p[i] < n-liked)
                    for (int j = 0; j < n; ++j) {
                        if(q[j] == p[i]) {
                            swap(q[j], q[i]);
                            break;
                        }
                    }
            }
        }
        for (auto &i:q) {
            cout << i << ' ';
        }
        cout << '\n';
    }

    return 0;
}