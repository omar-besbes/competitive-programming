#include "bits/stdc++.h"
using namespace std;

int main()
{
    int n, w;
    cin >> n >> w;
    vector<int> a(n), b(w);
    for (auto &i : a)
        cin >> i;
    for (auto &i : b)
        cin >> i;

    if (w == 1)
    {
        cout << n << "\n";
        return 0;
    }

    for (int i = 0; i < n - 1; i++)
        a[i] = a[i + 1] - a[i];
    a.pop_back();
    for (int i = 0; i < w - 1; i++)
        b[i] = b[i + 1] - b[i];
    b[w - 1] = -1;
    move(a.begin(), a.end(), back_inserter(b));

    int k = (n - 1) + 1 + (w - 1);
    vector<int> p(k);
    int ans = 0;
    for (int i = 1; i < k; i++)
    {
        int j = p[i - 1];
        while (j > 0 && b[i] != b[j])
            j = p[j - 1];
        p[i] = b[i] == b[j] ? j + 1 : 0;
        if (i > w && p[i] == w - 1)
            ans++;
    }

    /*
    for (int i = 0; i < k; i++)
        cout << p[i] << " ";
    cout << "\n";
    */

    cout << ans << "\n";
}