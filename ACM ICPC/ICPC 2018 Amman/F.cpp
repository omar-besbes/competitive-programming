#include <bits/stdc++.h>
#define seta 1000000
using namespace std;

int f[seta + 1];

int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//    cout.tie(nullptr);
//    freopen("name.in", "r", stdin);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w+", stdout);

    int t;
    cin >> t;

    vector<int> v[seta + 1];
    for (int i = 2; i < seta + 1; ++i) {
        for (int j = 1; j*i < seta + 1; j++) {
            v[j*i].push_back(i);
        }
    }

    while(t--) {
        int n;
        cin >> n;

        int a[n];
        for (int & i : a) {
            cin >> i;
        }
        sort(a, a+n);

        long long result = 0;

        for (int i = 0; i < n; ++i) {
            f[a[i]] = 1;
            for (int j = 0; j < v[a[i]].size(); ++j) {
                if(f[v[a[i]][j]]) {
                    result += v[a[i]][j];
                    break;
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            f[a[i]] = 0;
        }

        cout << result << '\n';
    }

    return 0;
}