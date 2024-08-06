#include "bits/stdc++.h"
using namespace std;

void solve() {
    pair<int, int> a, b;
    cin >> a.first >> a.second >> b.first >> b.second;

    int res = 0;
    if(a.first > b.first) {
        if(a.second >= b.second) res++;
    } 
    if(a.first == b.first) {
        if(a.second > b.second) res++;
    } 
    if(a.first > b.second) {
        if(a.second >= b.first) res++;
    } 
    if(a.first == b.second) {
        if(a.second > b.first) res++;
    } 
    if(a.second > b.first) {
        if(a.first >= b.second) res++;
    } 
    if(a.second == b.first) {
        if(a.first > b.second) res++;
    } 
    if(a.second > b.second) {
        if(a.first >= b.first) res++;
    } 
    if(a.second == b.second) {
        if(a.first > b.first) res++;
    }

    cout << res << "\n";
}

int main() {
    int t; cin >> t; while(t--) solve();
}