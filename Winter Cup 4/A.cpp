#include <bits/stdc++.h>

using namespace std;

int n, a[2005];
int dp[2005];

int solve(int idx)
{
    if(dp[idx]!=-1)
        return dp[idx];
    int f[2005];
    if(idx==n)
        return 1;
    for (int i = 1; i <= 2000; ++i) {
        f[i]=0;
    }
    int mex=1;
    for (int i = idx; i < n; ++i) {
        f[a[i]]++;
        if(f[a[i]]==2)
        {
            dp[idx]=0;
            return 0;
        }
        while(f[mex])
            mex++;
        if(mex==(i-idx+2) && solve(i+1)) {
            //cout << idx << ' ' << i << '\n';
            dp[idx]=1;
            return 1;
        }
    }
    dp[idx]=0;
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
//    freopen("name.in", "r", stdin);
 //   freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w+", stdout);
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i <= n; i++)
        dp[i]=-1;
    if(solve(0))
        cout << "YES\n";
    else
        cout << "NO\n";
   // for(int i = 0; i < n; i++)
     //   cout << dp[i] << ' ';

    return 0;
}