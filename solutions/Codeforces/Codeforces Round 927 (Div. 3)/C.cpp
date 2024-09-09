#include "bits/stdc++.h"
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    string s;
    for (auto &i : a)
    {
        cin >> i;
        i = i % m;
    }
    cin >> s;

    list<int> q;
    for (int i = 0, l = 0, r = n - 1; l <= r && i < n; i++)
    {
        if (s[i] == 'L')
            q.push_front(a[l]), l++;
        else
            q.push_front(a[r]), r--;
    }

    list<int> ans;
    int curr = 1;
    for (auto i : q)
    {
        curr = curr * i % m;
        ans.push_front(curr);
    }

    for(auto i: ans) cout << i << " ";
    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
}