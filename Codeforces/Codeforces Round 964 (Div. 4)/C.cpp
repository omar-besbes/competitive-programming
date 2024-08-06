#include "bits/stdc++.h"
using namespace std;

void solve() {
    int n, s, m; cin >> n >> s >> m;
    int l = 0, r = 0, ll = 0, lr = 0;
    bool res = false;
    for(int i=0; i<n; i++, ll=l, lr=r) {
        cin >> l >> r;
        if(l - lr >= s) res = true;
    }
    if(m - lr >= s) res = true;

    cout << (res ? "YES\n" : "NO\n");
}

int main() {
    int t; cin >> t; while(t--) solve();
}