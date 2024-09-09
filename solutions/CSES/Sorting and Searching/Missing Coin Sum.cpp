#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a)
        cin >> i;

    sort(a.begin(), a.end());

    /**
     * The idea is to keep track of the smallest sum we can make.
     * 
     * Let's say we have some coins with total value `x`.
     * We have to assume that we can make all sums less than or equal to `x`.
     * Now, if the next coin's value `y` is less than or equal to `x+1`, we can make sums up to `x+y`.
     * Not only `x+y` itself, but all sums between `x` and `x+y` because we assumed we can make these sums too.
     * 
     * Now, we can iterate through the coins from smallest to largest
     * and update the smallest sum we can make each time until we reach a coin the coin of value larger than `x+1`.
     * Indeed, we couldn't make `x+1` before we encountered the next coin. The next coin itself is bigger than `x+1`.
     * Since we are sure all coins after will only get bigger, we can stop here and say `x+1` is the smallest sum we can not make.
     */
    long long sum = 0;
    for (int i = 0; i < n && a[i] <= sum + 1; i++)
        sum += a[i];
    cout << sum + 1 << "\n";
}