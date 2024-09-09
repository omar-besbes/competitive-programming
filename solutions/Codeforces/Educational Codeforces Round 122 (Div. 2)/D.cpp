#include <bits/stdc++.h>

using namespace std;

int cost(int a) {
    int result = 0;
    while (a != 1) {
        if(a%2 != 0) {
            a--;
            result++;
        }
        while (a%2 == 0) {
            a /= 2;
            result++;
        }
    }
    return result;
}

int choose(pair<int, int> bc, int k, int r, int n) {
    /*
    for (auto &i:bc) {

    }
    */
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
    while (t--) {
        int n, k;
        cin >> n >> k;
        pair<int, int> bc[n];
        for (auto &i:bc) {
            cin >> i.first;
            i.first = cost(i.first);
        }
        for (auto &i:bc) {
            cin >> i.second;
        }
        sort(bc, bc+n);
        int index = 0, r = 0;
        while(index < n && bc[index].first == 0) {
            r+=bc[index].second;
            index++;
        }
        // choose(bc+index, k, r, n-index);
    }

    return 0;
}