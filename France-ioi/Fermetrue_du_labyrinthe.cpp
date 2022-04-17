#include <bits/stdc++.h>
using namespace std;
int nbN, nbS;
void explore(pair<vector<int>, bool> *N, int pos) {
    int n = N[pos].first.size();
    for (int i = 0; i < n; ++i) {
        if (!N[N[pos].first[i]].second)
            explore(N, N[pos].first[i]);
    }
    N[pos].second = true;
    cout << pos + 1 << " ";
}
bool contientBoucle(vector<int> *N, vector<bool> &visited, int pos) {
    if(visited[pos])
        return true;
    int n = N[pos].size();
    visited[pos] = true;
    for (int i = 0; i < n; ++i) {
        if(contientBoucle(N, visited, N[pos][i]))
            return true;
    }
    visited[pos] = false;
    return false;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("input.txt.txt", "r", stdin);
    freopen("output.txt", "w+", stdout);
    cin >> nbN >> nbS;
    pair<vector<int>, bool> containsParents[nbN];
    vector<int> containsChildren[nbN];
    for (int i = 0; i < nbS; ++i) {
        int n1, n2;
        cin >> n1 >> n2;
        n1--;
        n2--;
        containsParents[n2].first.push_back(n1);
        containsChildren[n1].push_back(n2);
        containsParents[n2].second = false;
        containsParents[n1].second = false;
    }
    bool estPossible = false;
    for (int i = 0; i < nbN; ++i) {
        vector<bool> visited(nbN);
        if(contientBoucle(containsChildren, visited, i)) {
            cout << "-1";
            return 0;
        }
    }
    for (int i = 0; i < nbN; ++i) {
        if(containsChildren[i].empty()) {
            estPossible = true;
            explore(containsParents, i);
        }
    }
    return 0;
}