#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("pair.in", "r", stdin);
    //freopen("input.txt.txt", "r", stdin);
    int t=1;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        long long cu=0;
        long long p=1;
        for(int i= s.length()-1; i >= 0; i--)
        {
            long long x= (int)(s[i]-'0');
            cu+=(p*x);
            p*=10;
            p%=k;
            cu%=k;
        }
        if(cu==0)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
