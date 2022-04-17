#include <bits/stdc++.h>

using namespace std;

vector<long long>tree[(1<<18)+1], tree_s[(1<<18)+1], p=(1<<17);

int n, m;




int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
//    freopen("name.in", "r", stdin);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w+", stdout);
    cin >> n >> m;
    int a[n+1];
    long long s[n+1];
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        s[i]+=a[i];
        if(i)
            s[i]+=s[i-1];
        tree[p+i].push_back(a[i]);
        tree_s[p+i].push_back(a[i]);
    }
    for (int i = p-1; i >= 0; --i) {
        int idx1=0, idx2=0;
        while(idx1 < tree[2*i].size() || idx2 < tree[2*i+1].size())
        {
            if(idx2 == tree[2*i+1].size() || (idx1 < tree[2*i].size() && tree[2*i][idx1] < tree[2*i+1][idx2]))
            {
                tree[i].push_back(tree[2*i][idx1]);
                idx1++;
            }
            else
            {
                tree[i].push_back(tree[2*i+1][idx2]);
                idx2++;
            }
        }
    }
    for (int i = p-1; i >= 0; --i) {
        int idx1=0, idx2=0;
        while(idx1 < tree_s[2*i].size() || idx2 < tree_s[2*i+1].size())
        {
            if(idx2 == tree_s[2*i+1].size() || (idx1 < tree_s[2*i].size() && tree_s[2*i][idx1] < tree_s[2*i+1][idx2]))
            {
                tree_s[i].push_back(tree_s[2*i][idx1]);
                idx1++;
            }
            else
            {
                tree_s[i].push_back(tree_s[2*i+1][idx2]);
                idx2++;
            }
        }
        for (int j = 1; j < tree_s[i].size(); ++j) {
            tree_s[i][j]+=tree_s[i][j-1];
        }
    }
    s[0]=0;
    while(m--)
    {
        long long l, r;
        cin >> l >> r;
        long long mm=s[r]-s[l-1];
        mm/=(r-l+1);
        long double mean=s[r]-s[l-1];
        mean/=(long double)(r-l+1);
        int x=p+l, y=p+r;
        long long ans=0;
        while(x <= y)
        {
            if(x%2==1)
            {long long idx= upper_bound(tree[x].begin(), tree[x].end(), mm)-tree[x].begin();
                ans+=(idx+1)*mean;
                ans-=(tree[x].size() -idx-1)*mean;
                ans-=(2LL)*tree_s[x][idx];
                ans+=tree_s[x].back();
                x++;
            }
            if(y%2==0)
            {
                long long idx= upper_bound(tree[y].begin(), tree[y].end(), mm)-tree[y].begin();
                ans+=(idx+1)*mean;
                ans-=(tree[x].size() -idx-1)*mean;
                ans-=(2LL)*tree_s[y][idx];
                ans+=tree_s[y].back();
                y--;
            }
            x/=2;
            y/=2;
        }
        cout << ans << '\n';
    }
    return 0;
}