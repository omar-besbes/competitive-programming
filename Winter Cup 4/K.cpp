#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
//    freopen("name.in", "r", stdin);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w+", stdout);
    long long n, m, cu1, cu2, cu3, ans;
    cin >> n >> m;
    if(n > m)
        swap(n, m);
    cu1=n+1;
    cu1*=n;
    cu1*=m;
    cu2=n;
    cu2*=(n+1LL);
    cu2/=(2LL);
    cu2*=(n+m);
    cu3=2*n+1LL;
    cu3*=(n+1LL);
    cu3*=n;
    cu3/=6;
    ans=cu1;
    ans-=cu2;
    ans+=cu3;
    //cout << cu1 << ' ' << cu2 << ' ' << cu3 << ' ' << ans << '\n';
    cout << ans << '\n';

    return 0;
}