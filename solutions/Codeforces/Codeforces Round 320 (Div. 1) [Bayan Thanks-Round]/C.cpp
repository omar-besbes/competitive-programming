#include "bits/stdc++.h"
using namespace std;

/**
 * It's safe and better to lower the precision in order to have better results
 * and guarantee the error margin.
 */
#define EPSILON 1e-8

int n;
vector<int> arr;

double f(double x)
{
    double curr = 0, maxi = 0;
    for (int i = 0; i < n; i++)
    {
        curr += arr[i] - x;
        if (curr < 0)
            curr = 0;
        else
            maxi = max(maxi, curr);
    }

    curr = 0;
    for (int i = 0; i < n; i++)
    {
        curr += x - arr[i];
        if (curr < 0)
            curr = 0;
        else
            maxi = max(maxi, curr);
    }

    return maxi;
}

int main()
{
    cin >> n;
    arr.assign(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    double l = -1e5, r = 1e5, m1, m2, f1 = f(l), f2 = f(r);
    // always add a constraint on the pointers l & r
    // even if the error does not depend on it
    while (r - l > EPSILON || abs(f1 - f2) > EPSILON)
    {
        m1 = l + (r - l) / 3;
        m2 = r - (r - l) / 3;
        f1 = f(m1), f2 = f(m2);
        if (f1 < f2)
            r = m2;
        // having the 2nd comparision or not does not make a big difference
        else if (f1 > f2)
            l = m1;
        else
            l = m1, r = m2;
    }

    // don't forget to recompute the value
    // we don't know which of f1 or f2 was last updated
    // after breaking out of the loop
    cout << setprecision(16) << f((l + r) / 2) << "\n";
}