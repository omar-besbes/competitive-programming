#include "bits/stdc++.h"
using namespace std;

const long long n = 1e12;
vector<long long> squares;

void solve()
{
    long long n;
    cin >> n;
    long long ans = n;
    for (int i = 0; i < squares.size(); i++)
    {
        auto x = squares[i];
        auto y = n - x;
        auto aprrx1 = upper_bound(squares.begin(), squares.end(), y);
        long long aprrx2;

        if (aprrx1 != squares.end())
        {
            ans = min(ans, abs(n - x - *aprrx1));
            int idx = aprrx1 - squares.begin();
            aprrx2 = squares[max(0, idx - 1)];
        }
        else
        {
            aprrx2 = squares.back();
        }

        ans = min(ans, abs(n - x - aprrx2));

        if (aprrx2 <= x)
            break;
    }

    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    for (long long i = 0; i * i <= n; i++)
        squares.push_back(i * i);

    int t;
    cin >> t;
    while (t--)
        solve();
}
