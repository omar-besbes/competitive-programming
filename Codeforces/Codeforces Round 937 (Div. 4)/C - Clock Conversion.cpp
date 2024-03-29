#include "bits/stdc++.h"
 
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    int t;
    cin >> t;
    while (t--)
    {
        int h, m;
        char c;
        cin >> h >> c >> m;
        if (h >= 12)
            cout << setw(2) << setfill('0') << (h - 12 ? h - 12 : 12) << c << setw(2) << setfill('0') << m << " PM\n";
        else
            cout << setw(2) << setfill('0') << (h ? h : 12) << c << setw(2) << setfill('0') << m << " AM\n";
    }
}