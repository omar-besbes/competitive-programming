#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("xorsum.in", "r", stdin);
    //freopen("input.txt.txt", "r", stdin);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string a, b;
        cin >> a >> b;
        int nb0=0, nb1=0;
        //cout << a << ' ' << b << '\n';
        for(int i = 0; i < n; i++)
        {
            if(a[i]==b[i])
            {
                if(a[i]==1)
                    nb1++;
                else
                    nb0++;
            }
        }
        if(nb1==0 || (nb1==1 && nb0 > 0))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}


