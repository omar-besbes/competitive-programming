#include "bits/stdc++.h"

using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w+", stdout);

    int a, b, ans = 0;
    map<int, int> mapa, mapb;
    set<int> primes;

    cin >> a >> b;
    if (a == b) cout << 0;
    else {
        for (int i = 2; i * i < a; ++i) {
            while (a % i == 0) {
                primes.insert(i);
                mapa[i]++;
                a /= i;
            }
        }
        for (int i = 2; i * i < b; ++i) {
            while (b % i == 0) {
                primes.insert(i);
                mapb[i]++;
                b /= i;
            }
        }
        for (auto i: primes) {
            if (i != 2 && i != 3 && i != 5) {
                if (mapa[i] != mapb[i]) {
                    cout << -1;
                    return 0;
                }
            }
            else ans += abs(mapa[i] - mapb[i]);
        }
    }
    cout << ans;

    return 0;
}