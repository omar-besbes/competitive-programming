#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct Point
{
    ll x, y;
    void read() { cin >> x >> y; }
    Point operator-(const Point &b) const { return Point({x - b.x, y - b.y}); }
    ll operator*(const Point &b) const { return x * b.y - y * b.x; }
    ll cross(const Point &b, const Point &c)
    {
        return (b - *this) * (c - *this);
    }
};

void solve()
{
    ll n;
    cin >> n;
    vector<Point> a(n);
    vector<bool> b(n, false);
    for (auto &i : a)
        i.read();

    auto next = [&](int idx)
    {
        int i = (idx + 1) % n;
        while (b[i])
            i++, i %= n;
        return i;
    };

    int x = 0, y = 1, z = 2;
    ll ans = 0;
    for (int count = 0; n - count >= 3; count++)
    {
        b[y] = true;
        ans += (a[y].cross(a[x], a[z]));
        x = z;
        y = next(z);
        z = next(y);
    }

    cout << abs(ans) << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--)
        solve();
}