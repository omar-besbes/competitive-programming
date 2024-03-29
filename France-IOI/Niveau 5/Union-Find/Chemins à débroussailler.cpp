#include "bits/stdc++.h"
using namespace std;

int n, a, maxi;
vector<int> p, s;

void init()
{
    p.resize(n);
    s.resize(n);
    s.assign(n, 1);
    maxi = 1;
    for (int i = 0; i < n; i++)
    {
        p[i] = i;
    }
}

int getp(int a)
{
    if (p[a] == a)
        return a;
    return p[a] = getp(p[a]);
}

void merge(int a, int b)
{
    int pa = getp(a), pb = getp(b);
    if (pa == pb)
        return;
    if (s[pa] < s[pb])
        swap(pa, pb);
    p[pb] = pa;
    s[pa] += s[pb];
    maxi = max(maxi, s[pa]);
}

void print()
{
    cout << "s ";
    for (auto &i : s)
        cout << i << " ";
    cout << "\n"
         << "p ";
    for (auto &i : p)
        cout << i << " ";
    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> a;
    init();

    for (int i = 0; i < a; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        merge(a - 1, b - 1);
        cout << maxi << "\n";
    }
}