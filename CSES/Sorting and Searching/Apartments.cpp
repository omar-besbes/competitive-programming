#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n), b(m);
    for (auto &i : a)
        cin >> i;
    for (auto &j : b)
        cin >> j;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int i = 0, j = 0, ans = 0;
    for (; i < n && j < m;)
    {
        if (a[i] > b[j] + k)
            j++;
        else if (a[i] < b[j] - k)
            i++;
        else
            i++, j++, ans++;
    }
    cout << ans;
}