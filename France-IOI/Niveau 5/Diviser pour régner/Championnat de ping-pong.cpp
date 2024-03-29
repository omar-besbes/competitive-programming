#include "bits/stdc++.h"
using namespace std;

int h, n, k;
vector<int> a;

void print(string message, set<int> a)
{
    cout << message << " ";
    for (auto &i : a)
        cout << i << " ";
    cout << "\n";
}

set<int> explore(int l = 0, int r = n - 1)
{
    set<int> ans;
    if (l == r)
    {
        ans.insert(a[l]);
    }
    else
    {
        int m = (l + r) / 2;
        auto left = explore(l, m);
        auto right = explore(m + 1, r);

        // print("left", left);
        // print("right", right);

        for (int i : {0, 1})
        {
            for (auto &i : left)
            {
                auto mini = *min_element(right.begin(), right.end());
                if (i > mini - k)
                    ans.insert(i);
            }
            swap(left, right);
        }
    }
    return ans;
}

int main()
{
    cin >> h >> k;
    n = 1 << h;
    a.resize(n);
    for (auto &i : a)
        cin >> i;

    auto candidates = explore();
    auto ans = *min_element(candidates.begin(), candidates.end());
    cout << ans << "\n";
}