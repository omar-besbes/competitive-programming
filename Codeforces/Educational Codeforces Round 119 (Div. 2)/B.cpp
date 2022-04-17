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
    while(t--) {
        int w, h, maxi = 0;
        cin >> w >> h;
        pair<vector<int>, int> side[4];
        for (auto & i : side) {
            int k, p;
            cin >> k;
            i.second = 0;
            for (int j = 0; j < k; ++j) {
                cin >> p;
                i.first.push_back(p);
            }
            i.second = i.first.back() - i.first.front();
        }
        for (int i = 0; i < 4; ++i) {
            if(i <= 1)
                maxi = max(maxi, side[i].second * h);
            else
                maxi = max(maxi, side[i].second * w);
        }
        cout << maxi << '\n';
    }

    return 0;
}