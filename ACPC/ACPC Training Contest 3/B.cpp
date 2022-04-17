#include <bits/stdc++.h>
using namespace std;

int n, m;
set<string> possibilites;

void Possibility(string &s, char c, int pos) {
    for (int i = 0; i < m; ++i) {
        s[pos] = (char) (97+i);
        possibilites.insert(s);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
//    freopen("challenge.in", "r", stdin);
    freopen("input.txt.txt", "r", stdin);
    freopen("output.txt", "w+", stdout);

    cin >> n >> m;
    string s, x;
    cin >> s;
    possibilites.insert(s);
    for (int i = 0; i < n; ++i) {
        x = s;
        Possibility(x, x[i], i);
    }
    x = s.substr(1, n-1) + '.';
    Possibility(x, '.', n-1);
    x = '.' + s.substr(0, n-1);
    Possibility(x, '.', 0);
    cout << possibilites.size()-1 << '\n';

    for (auto i:possibilites) {
        cout << i << ' ';
    }

    return 0;
}