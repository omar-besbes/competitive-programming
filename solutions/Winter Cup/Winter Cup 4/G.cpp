#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int> > sieve[1000005];
int a[1000005], b[1000005];

void init() {
    for (int i = 2; i <= 1000000; ++i) {
        if (sieve[i].empty())
            for (int j = i; j <= 1000000; j += i)
                sieve[j].push_back(make_pair(i, 0));
        int x = i;
        for (int j = 0; j < sieve[i].size(); ++j) {
            while (x % sieve[i][j].first == 0) {
                x /= sieve[i][j].first;
                sieve[i][j].second++;
            }
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
//  freopen("name.in", "r", stdin);
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w+", stdout);

    int n, l;
    cin >> n >> l;
    init();
    int s1 = 0, s2 = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        for (int j = 0; j < sieve[x].size(); ++j) {
            s1 += sieve[x][j].second;
            a[sieve[x][j].first] += sieve[x][j].second;
        }
    }
    int mi = 1000000000, nb1, nb2;
    for (int i = 1; i <= l; i++) {
        if (sieve[i].size() == 1 && sieve[i][0].second == 1)
            mi = min(mi, a[i]);
    }
    nb1 = mi;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        for (int j = 0; j < sieve[x].size(); ++j) {
            s2 += sieve[x][j].second;
            b[sieve[x][j].first] += sieve[x][j].second;
        }
    }
    mi = 1000000000;
    for (int i = 1; i <= l; i++) {
        //cout << b[i] << ' ';
        if (sieve[i].size() == 1 && sieve[i][0].second == 1) {
            mi = min(mi, b[i]);
            // cout << i << '\n';
        }
    }
    // cout << '\n';
    nb2 = mi;
    //cout << nb1 << ' ' << nb2 << '\n';
    /* if(nb2==0)
         cout << "Rami\n";
     else if(nb1==0)
         cout << "Yessine\n";*/
    if (nb2 <= nb1)
        cout << "Rami\n";
    else
        cout << "Yessine\n";
    return 0;
}