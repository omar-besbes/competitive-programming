#include <bits/stdc++.h>
 
using namespace std;
 
int n, q;
vector<long long> *a, *seg;
 
void build(int index = 1, int seg_l = 0, int seg_r = n - 1) {
    if (seg_l == seg_r) {
        (*seg)[index] = (*a)[seg_l];
    } else {
        int seg_m = (seg_l + seg_r) / 2;
        build(2 * index, seg_l, seg_m);
        build(2 * index + 1, seg_m + 1, seg_r);
        (*seg)[index] = 0;
    }
}
 
long long xor_sum(int l, int r, int index = 1, int seg_l = 0, int seg_r = n - 1) {
    if (l > r)
        return 0;
 
    if (l == seg_l && r == seg_r) {
        return (*seg)[index];
    }
 
    int seg_m = (seg_l + seg_r) / 2;
    return xor_sum(l, min(seg_m, r), 2 * index, seg_l, seg_m) ^
           xor_sum(max(l, seg_m + 1), r, 2 * index + 1, seg_m + 1, seg_r);
}
 
void update(int l, int r, int val, int index = 1, int seg_l = 0, int seg_r = n - 1) {
    if (l > r) return;
    if (seg_l == l && seg_r == r) {
        (*seg)[index] += val;
    } else {
        int seg_m = (seg_l + seg_r) / 2;
        update(l, min(r, seg_m), val, 2 * index, seg_l, seg_m);
        update(max(l, seg_m + 1), r, val, 2 * index + 1, seg_m + 1, seg_r);
    }
}
 
long long get(int pos, int index = 1, int seg_l = 0, int seg_r = n - 1) {
    if (pos < seg_l || pos > seg_r) return -1;
 
    if (seg_l == seg_r && seg_r == pos) {
        return (*seg)[index];
    } else {
        int seg_m = (seg_l + seg_r) / 2;
        if (pos <= seg_m) {
            return (*seg)[index] + get(pos, 2 * index, seg_l, seg_m);
        } else {
            return (*seg)[index] + get(pos, 2 * index + 1, seg_m + 1, seg_r);
        }
    }
}
 
void print(int index = 1, int seg_l = 0, int seg_r = n - 1) {
    if (seg_l == seg_r)
        cout << index << ": " << (*seg)[index] << " ";
    else {
        cout << index << ": " << (*seg)[index] << "\n";
 
        int seg_m = (seg_l + seg_r) / 2;
        print(2 * index, seg_l, seg_m);
        cout << " ";
        print(2 * index + 1, seg_m + 1, seg_r);
        cout << "\n";
    }
}
 
int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//    cout.tie(nullptr);
 
    cin >> n >> q;
    a = new vector<long long>(n);
    seg = new vector<long long>(4 * n);
 
    for (int i = 0; i < n; ++i) {
        cin >> (*a)[i];
    }
 
    build();
 
    int x, y, k, u, type;
    while (q--) {
        cin >> type;
        if (type == 1) {
            cin >> x >> y >> u;
            update(x - 1, y - 1, u);
        } else {
            cin >> k;
            cout << get(k - 1) << "\n";
        }
    }
}