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
        int n;
        cin >> n;
        int a[n], op = 0;
        vector<int> maxi;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        for (int i = 1; i < n-1; ++i) {
            if(a[i] > a[i-1] && a[i] > a[i+1]) {
                maxi.push_back(i);
            }
        }

        for (int i = 0; i+1 < maxi.size(); i += 2) {
            int filler = max(a[maxi[i]], a[maxi[i+1]]);
            for (int j = maxi[i] + 1; j < maxi[i + 1]; ++j) {
                if(a[j] - filler)
                    a[j] = filler;
                else op--;
            }
            op += maxi[i + 1] - (maxi[i] + 1);
        }
        if(maxi.size() % 2 != 0) {
            if(maxi.size() > 1){
                int filler = max(a[*(maxi.end() - 2)], a[*(maxi.end() - 1)]);
                for (int j = *(maxi.end() - 2) + 1; j <*(maxi.end() - 1); ++j) {
                    if(a[j] - filler)
                        a[j] = filler;
                    else op--;
                }
                op += *(maxi.end() - 1) - (*(maxi.end() - 2) + 1);
            } else {
                if()
            }
        }

        cout << op << "\n";
        for (int i = 0; i < n; ++i) {
            cout << a[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}