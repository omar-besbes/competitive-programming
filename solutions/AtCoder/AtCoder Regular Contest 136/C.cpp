#include <bits/stdc++.h>

using namespace std;

int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//    cout.tie(nullptr);
//    freopen("name.in", "r", stdin);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w+", stdout);

    int n, sum = 0;
    cin >> n;
    vector<int> a(n), x(n), maxis;
    for (auto i:a) {
        cin >> i;
    }
    auto minimaxi = minmax_element(a.begin(), a.end());
    for (int i = 0; i < n; ++i) {
        if(a[i] == *minimaxi.second)
            maxis.push_back(i);
        a[i] -= *minimaxi.first;
    }
    int tmp[n];
    adjacent_difference(maxis.begin(), maxis.end(), tmp);
    for (auto &i : tmp) {
        sum += i;
    }    
    if(sum == maxis.size()-1)
        for (auto i:maxis) {
            a[i]--;
        }
    if(*minimaxi.first)
        sum = 1;
    else sum = 0;
    if(a[0] && a[n-1]) {
        int debut = 0, fin = n-1, maxi = 0;
        while (a[debut]) {
            maxi = max(maxi, a[debut]);
            debut++;
        }
        while (a[fin]) {
            maxi = max(maxi, a[fin]);
            fin--;
        }
    }


    return 0;
}