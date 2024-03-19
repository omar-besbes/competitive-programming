#include<bits/stdc++.h>

using namespace std;

string ts(int x)
{
    string s;
    while(x)
    {
        s+=((char)(x%10)+'0');
        x/=10;
    }
    sort(s.begin(), s.end());
    return s;
}
//int c[10][10];
int main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    freopen("phi.in", "r", stdin);
    int t;
    cin >> t;
    vector<int>v[1000005];
    //cout << '\n';
    for(long long i = 2; i <= 1000000; i++)
    {
        if(v[i].empty())
        {
            bool b=true;
            for(long long j = 2; b; j++)
            {
                long long cu=j*i;
                if(cu <= 1000000)
                    v[j*i].push_back(i);
                else
                    b=false;
            }
        }
        //for(int j = 0; j < v[i].size(); j++)
        //cout << v[i][j] << ' ';
        //cout << '\n';
    }
    //v[i]={primes that divide i}
    //00000001
    while(t--)
    {
        long long n;
        cin >> n;
        long long nb = v[n].size();
        long long ans=n-1;
        int x = (1<<nb);
        for(int perm=1; perm < x; perm++)
        {
            int nb_1=0, nb_cu=0;
            int cu_perm=perm;
            long long prod=1;
            while(cu_perm)
            {
                if(cu_perm%2)
                {
                    nb_1++;
                    prod*=v[n][nb_cu];
                }
                nb_cu++;
                cu_perm/=2;
            }
            if(prod!=1)
            {
                if(nb_1%2)
                    ans-=((n-1)/prod);
                else
                    ans+=((n-1)/prod);
            }
        }
        //cout << ans << '\n';
        if(ts(ans)==ts(n))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}

