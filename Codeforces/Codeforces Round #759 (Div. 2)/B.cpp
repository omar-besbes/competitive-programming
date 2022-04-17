#include <bits/stdc++.h>
using namespace std;

int indiceMax(vector<int> &a, int start) {
    pair<int, int> max = {a[start], start};
    auto size = a.size();
    for (int i = start + 1; i < size; ++i)
        if(max.first <= a[i]) {
            max.first = a[i];
            max.second = i;
        }
    return max.second;
}

int eversion(vector<int> &a, int start) {
    if(start == a.size()-1)
        return 0;
    return 1 + eversion(a, indiceMax(a, start + 1));
}

int main()
{
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//    cout.tie(nullptr);
//    freopen("challenge.in", "r", stdin);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w+", stdout);

    int t;
    cin >> t;
    while(t--) {
        int n, x, indice = 0;
        pair<int, int> maxi = {-1, 0};
        cin >> n;
        vector<int> a;
        for (int i = 0; i < n; ++i) {
            int y;
            cin >> y;
            if(maxi.first <= y) {
                maxi.first = y;
                maxi.second = i;
            }
            a.push_back(y);
        }

        cout << eversion(a, maxi.second) <<'\n';
    }

    return 0;
}