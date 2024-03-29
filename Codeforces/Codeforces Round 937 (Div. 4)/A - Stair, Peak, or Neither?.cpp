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
        int a, b, c;
        cin >> a >> b >> c;
        if (a < b && b < c)
            cout << "STAIR\n";
        else if (a < b && b > c)
            cout << "PEAK\n";
        else
            cout << "NONE\n";
    }
}