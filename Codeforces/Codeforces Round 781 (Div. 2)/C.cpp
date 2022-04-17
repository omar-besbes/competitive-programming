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
        int n;
        cin >> n;
        vector<int> v(n + 1), a;
        v[0] = 1;
        for (int i = 1; i < n; ++i) {
            int x;
            cin >> x;
            v[x]++;
        }

        sort(v.rbegin(), v.rend());
        int seconds = 0, p = 0, mini = v[0];
        for (int i = 0; i < n + 1; ++i) {
            if (v[i]) p++;
        }
        seconds = p;
        for (int i = 0; i < n + 1; ++i) {
            if (v[i]) {
                if (v[i] > p) {
                    v[i] -= p;
                    a.push_back(v[i]);
                    mini = min(mini, v[i]);
                } else {
                    v[i] = 0;
                }
                p--;
            }
        }

        int b[a.size()];
        while (!a.empty() && a[0]) {

            // nahhi mini healthy men kol group w nahi mini healthy men akber group

            int nb = 0;
            for (int &i: a) {
                if (i) nb++;
            }

            if (nb == 1) {
                seconds += ceil((double) a[0] / 2);
                break;
            } else {
                seconds += mini;
                for (int &i: a) {
                    i = max(i - mini, 0);
                }
                adjacent_difference(a.begin(), a.end(), b);
                int new_mini = mini;
                for (int i = 1; i < a.size(); i++) {
                    a[i - 1] -= min(mini, b[i - 1]);
                    mini -= min(mini, b[i - 1]);
                    if (a[i - 1]) new_mini = min(new_mini, a[i - 1]);
                }
                mini = new_mini;
            }
        }

        cout << seconds << "\n";
    }

    return 0;
}