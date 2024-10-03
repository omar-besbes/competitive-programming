#include <bits/stdc++.h>
using namespace std;
#define pred(x) predecessor[x.first][x.second]
#define g(x) g[x.first][x.second]

typedef pair<int, int> pii;

int n, m;

pii operator+(pii a, pii b)
{
    return {a.first + b.first, a.second + b.second};
}
pii operator-(pii a, pii b)
{
    return {a.first - b.first, a.second - b.second};
}
bool operator!=(pii a, pii b)
{
    return a.first != b.first || a.second != b.second;
}
bool is_win(pii x)
{
    return x.first == 0 || x.second == 0 || x.first == n - 1 || x.second == m - 1;
}
bool is_valid(pii x)
{
    return x.first >= 0 && x.first < n && x.second >= 0 && x.second < m;
}

const vector<pair<pii, char>> d{{{1, 0}, 'D'}, {{0, 1}, 'R'}, {{-1, 0}, 'U'}, {{0, -1}, 'L'}};

vector<string> g;

void print_grid()
{
    cout << "\n";
    for (int i = 0; i < n; i++)
        cout << g[i] << "\n";
    cout << "\n\n";
}

void solve()
{
    cin >> n >> m;
    g.resize(n);
    set<pii> monsters, next_monsters;
    pii initial_person, final_person;
    set<pii> person, next_person;
    for (int i = 0; i < n; i++)
    {
        cin >> g[i];
        for (int j = 0; j < m; j++)
        {
            if (g[i][j] == 'M')
                monsters.insert({i, j});
            if (g[i][j] == 'A')
                initial_person = {i, j};
        }
    }

    bool yes = false;
    person.insert(initial_person);
    vector<vector<pii>> predecessor(n, vector<pii>(m));
    while (!person.empty() && !yes)
    {
        for (auto coo : person)
            if (g(coo) == 'A')
            {
                if (is_win(coo))
                    yes = true, final_person = coo;
                for (auto [dxy, _] : d)
                {
                    auto newcoo = coo + dxy;
                    if (is_valid(newcoo) && g(newcoo) == '.')
                        g(newcoo) = 'A', next_person.insert(newcoo), pred(newcoo) = coo;
                }
            }

        for (auto coo : monsters)
            for (auto [dxy, _] : d)
            {
                auto newcoo = coo + dxy;
                if (is_valid(newcoo) && g(newcoo) != '#' && g(newcoo) != 'M')
                    g(newcoo) = 'M', next_monsters.insert(newcoo);
            }

        person = next_person;
        next_person.clear();
        monsters = next_monsters;
        next_monsters.clear();
        // print_grid();
    }

    cout << (yes ? "YES" : "NO") << "\n";
    if (yes)
    {
        string path;
        for (pii cur = final_person; cur != initial_person; cur = pred(cur))
            for (auto [dxy, direction] : d)
                if (dxy == cur - pred(cur))
                    path += direction;
        reverse(path.begin(), path.end());

        cout << path.length() << "\n";
        cout << path << "\n";
    }
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

/**
 *
5 100
####################################################################################################
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM....................................................
################################################MA##################################################
..................................................MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
####################################################################################################

5 8
########
#M..A#.#
#.#.##..
#M#....#
#.######
 *
 */