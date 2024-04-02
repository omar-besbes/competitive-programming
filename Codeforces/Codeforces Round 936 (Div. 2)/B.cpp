#include "bits/stdc++.h"
using namespace std;

#define MOD (int)1e9 + 7

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int max_sum = 0;
        long long min_sum = 0, sum = 0;
        cout << (-4) % MOD << " ";
        for (int i = 0; i < n; i++)
        {
            sum += a[i];
            cout << sum - min_sum << " ";
            max_sum = max(max_sum, (int)((sum - min_sum) % MOD));
            cout << max_sum << " ";
            min_sum = min(min_sum, sum);
        }
        int ans = max_sum;
        cout << "max_sum:" << max_sum << " ";
        for (int i = 0; i < k; i++)
        {
            long long tmp = max_sum;
            ans = max(ans, (int)((tmp << i) % MOD));
        }
        cout << "ans:" << ans << " ";
        cout << (ans + sum - max_sum) % MOD << "\n";
    }

    return 0;
}