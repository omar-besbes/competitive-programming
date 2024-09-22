#include "bits/stdc++.h"
using namespace std;

int main()
{
    int n;
    cin >> n;
    int k = 5, e = 1;
    while (5 * k <= n)
        k *= 5, e++;

    vector<bool> m5(n / 5 + 1);
    long long ans = 0;
    for (int i = k; i >= 5; i /= 5, e--)
        for (int j = i; j <= n; j += i)
            if (!m5[j / 5])
                m5[j / 5] = true, ans += e;

    cout << ans;
}