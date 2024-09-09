#include "bits/stdc++.h"
using namespace std;

int find_max_easy(priority_queue<int, vector<int>, greater<int>> &s, int n)
{
    if (n <= 2)
        return 0;
    if (n == 3)
        return 1;
    if (s.size() <= 1)
        return 0;
    if (s.size() == 2)
    {
        int min1 = s.top();
        s.pop();
        int min2 = s.top();
        s.push(min1);
        int diff = min2 - min1;
        if (diff == 1 || n - diff == 1)
            return 0;
        else if (diff == 2 || n - diff == 2)
            return 1 + (n - 1 == 3 ? 1 : 0);
        else
            return 0;
    }
    // using the first 3 vertices, make a triangle and remove it.
    // this will create 3 other shapes:
    // in 2 of which, there are 2 chosen vertices (size of x == 2) and the chosen vertices are adjacent.
    // so, these 2 shapes will either be a triangle or will not contribute to the sum.
    // the last shape we must explore it recursively as it contains x - 1 chosen vertices.
    int a = s.top();
    s.pop();
    int b = s.top();
    s.pop();
    int c = s.top();
    s.push(c - 1);

    return 1 +
           find_max_easy(s, n - (c - a + 1) + 2) +
           (b - a + 1 == 3 ? 1 : 0) +
           (c - b + 1 == 3 ? 1 : 0);
}

int find_max_easy_optimized(priority_queue<int, vector<int>, greater<int>> &s, int n)
{
    int ans = s.size() - 2;
    int first = s.top();
    while (s.size() > 1)
    {
        int curr = s.top();
        s.pop();
        int next = s.top();
        if (next - curr == 2)
            ans++;
    }
    int last = s.top();
    if (n - (last - first) == 2)
        ans++;
    return ans;
}

int find_max_hard(priority_queue<int, vector<int>, greater<int>> &s, int n, int y)
{
    int ans = s.size() - 2;
    priority_queue<int, vector<int>, function<bool(int, int)>>
        gaps([](int l, int r)
             { return l & 1 == r & 1 ? l < r
                      : l & 1 == 1   ? l
                                     : r; });
    int first = s.top();
    while (s.size() > 1)
    {
        int curr = s.top();
        s.pop();
        int next = s.top();
        gaps.push(next - curr - 1);
    }
    int last = s.top();
    gaps.push(n - (last - first) - 1);

    while (y >= 0 && !gaps.empty())
    {
        int curr = gaps.top();
        gaps.pop();
        if (y >= curr / 2)
            y -= curr / 2, ans += curr;
        else
            ans += y * 2, y = 0;
    }

    return ans;
}

void solve()
{
    int n, x, y;
    cin >> n >> x >> y;
    priority_queue<int, vector<int>, greater<int>> s;
    for (int i = 0; i < x; i++)
    {
        int a;
        cin >> a;
        s.push(a);
    }
    cout << find_max_hard(s, n, y) << "\n";
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