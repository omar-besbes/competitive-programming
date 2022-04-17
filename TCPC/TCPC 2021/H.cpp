#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
using namespace __gnu_pbds;
using namespace std;
typedef
tree<
        pair<int,int>,
        null_type,
        less<pair<int,int> >,
        rb_tree_tag,
        tree_order_statistics_node_update>
        ordered_set;

int a[100005], b[100005], c[100005];
vector<int>ans;
vector<int>v[100005];
//set<pair<int, int> >s[100005];
ordered_set mark(int idx, int anc)
{
    if(idx!=1 && v[idx].size() == 1)
    {
        ans[idx-1]=a[idx];
        ordered_set cu;
        cu.insert(make_pair(a[idx], idx));
        return cu;
    }
    ordered_set cu, cu1;
    for(int i = 0; i < v[idx].size(); i++)
        if(v[idx][i]!=anc) {
            cu1=mark(v[idx][i], idx);
            if(cu.size() < cu1.size())
                swap(cu, cu1);
            cu.insert();
        }
    int nb;
    nb*=cu.size();
    int la=(b[idx]*nb)/100;
    if((b[idx]*nb)%100)
        nb++;
    ans[idx-1]=cu[la-1];
    cu.insert(make_pair(ans[idx-1], idx));
    return cu;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("artwork.in", "r", stdin);
    //freopen("input.txt.txt", "r", stdin);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        ans.clear();
        for(int i = 0; i < n; i++)
            ans.push_back(0);
        for(int i = 1; i <= n; i++) {
            v[i].clear();
            s[i].clear();
        }
        for(int i = 1; i <= n; i++)
            cin >> a[i];
        for(int i = 1; i <= n; i++)
            cin >> b[i];
        for(int i = 1; i <= n; i++)
            cin >> c[i];
        for(int i = 0; i < n-1; i++)
        {
            int x, y;
            cin >> x >> y;
            v[x].push_back(y);
            v[y].push_back(x);
        }
        if(n == 1)
            ans[1]=a[1];
        else
            mark(1, 1);
    }
}


