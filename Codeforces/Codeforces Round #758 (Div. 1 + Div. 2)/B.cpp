#include <bits/stdc++.h>
using namespace std;

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
        int n, nMax, nMin;
        cin >> n >> nMax >> nMin;
        if(abs(nMin - nMax) > 1 || nMax + nMin > n-2) {
            cout << "-1\n";
            continue;
        }

        if(nMin == nMax){
            int i;
            cout << "1 ";
            for (i = 2; nMax && i < n; i+=2, nMax--) {
                cout << i+1 << ' ' << i << ' ';
            }
            while (i <= n)
                cout << i++ << " ";
            cout << '\n';
        } else if(nMax > nMin) {
            int i;
            cout << "1 ";
            for (i = 2; nMin && i < n; i+=2, nMin--) {
                cout << i+1 << ' ' << i << ' ';
            }
            while (i <= n-2)
                cout << i++ << " ";
            cout << n << ' ' << n-1 << '\n';
        } else {
            int i;
            cout << "2 1 ";
            for (i = 3; nMax && i < n; i+=2, nMax--) {
                cout << i+1 << ' ' << i << ' ';
            }
            while (i <= n)
                cout << i++ << " ";
            cout << '\n';
        }
    }

    return 0;
}