#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<long long, long long>
#define mkp make_pair

struct Point
{
    ll x, y;
    void read() { cin >> x >> y; }
    Point operator+(const Point &b) const { return Point({x + b.x, y + b.y}); }
    Point operator-(const Point &b) const { return Point({x - b.x, y - b.y}); }
    ll operator*(const Point &b) const { return x * b.y - y * b.x; }
    ll cross(const Point &b, const Point &c)
    {
        return (b - *this) * (c - *this);
    }
    bool between(const Point &b, const Point &c)
    {
        Point bl({min(b.x, c.x), min(b.y, c.y)}), tr({max(b.x, c.x), max(b.y, c.y)});
        return x >= bl.x && x <= tr.x && y >= bl.y && y <= tr.y;
    }
};

void solve()
{
    Point p1, p2, p3, p4;
    p1.read(), p2.read(), p3.read(), p4.read();

    // parallel lines
    if ((p1 - p2) * (p3 - p4) == 0)
    {
        // collinear lines
        if (p1.cross(p2, p3) == 0)
        {
            if (p1.between(p3, p4) || p2.between(p3, p4) || p3.between(p1, p2) || p4.between(p1, p2))
                cout << "YES\n";
            else
                cout << "NO\n";
        }
        // parallel but non collinear never intersect
        else
        {
            cout << "NO\n";
        }
    }
    // lines intersect
    else
    {
        auto s123 = p1.cross(p2, p3);
        auto s124 = p1.cross(p2, p4);
        auto s341 = p3.cross(p4, p1);
        auto s342 = p3.cross(p4, p2);

        // from the POV of one of the lines, the other line is on its right/left without touching it
        if ((s123 > 0 && s124 > 0) || (s123 < 0 && s124 < 0) || (s341 < 0 && s342 < 0) || (s341 > 0 && s342 > 0))
        {
            cout << "NO\n";
        }
        else
        {
            cout << "YES\n";
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--)
        solve();
}