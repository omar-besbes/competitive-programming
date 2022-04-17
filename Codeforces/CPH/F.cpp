#include <bits/stdc++.h>

using namespace std;

int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//    cout.tie(nullptr);
//    freopen("name.in", "r", stdin);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w+", stdout);

    int n, m,  k, op = 0;
    cin >> n >> m >> k;
    vector<set<int>> g; // vector of groups of same color
    pair<int, int> s[n]; // first is color
    for (int i = 0; i < n; ++i) {
        cin >> s[i].first;
        s[i].second = -1;
    }

    for (int i = 0; i < m; ++i) {
        int r, l;
        cin >> r >> l;
        if(s[r-1].second == -1 && s[l-1].second == -1) {
            g.push_back({r-1, l-1});
            s[l-1].second = g.size()-1;
            s[r-1].second = s[l-1].second;
        }
        else if(s[r-1].second != -1 && s[l-1].second != -1 && s[r-1].second != s[l-1].second) {
            if(g[s[l-1].second].size() > g[s[r-1].second].size()) {
                swap(l, r);
            }
            int index_grp_to_erase = s[l-1].second;
            for (auto &j: g[s[l-1].second]) {
                g[s[r-1].second].insert(j);
                s[j].second = s[r-1].second;
            }
            g.erase(g.begin() + index_grp_to_erase);
            g.insert(g.begin() + index_grp_to_erase, {});
        }
        else {
            if(s[l-1].second != -1)
                swap(l, r);
            s[l-1].second = s[r-1].second;
            g[s[r-1].second].insert(l-1);
        }
    }

    for (auto & i : g) {
        if(i.empty()) continue;
        map<int, int> grp;
        for (auto &j:i) {
            grp.insert({j, 1});
        }

        int maxi = max_element(grp.begin(), grp.end())->first;
        int sum = i.size();
        op += sum - maxi;
    }

    cout << op;

    return 0;
}