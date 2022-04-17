#include <bits/stdc++.h>

using namespace std;

void genereatePrimes(vector<int> &primes, int maxi) {
    vector<bool> a(maxi+1, true);
    for (int i = 2; i < maxi + 1; ++i) {
        if (a[i]) {
            primes.push_back(i);
            for (int j = i * i; j < maxi + 1; j += i) {
                a[j] = false;
            }
        }
    }
}

void readArray(int n, const vector<int>& primes, map<int, int> &map) {
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        for (auto j: primes) {
            while (x % j == 0 && x > 1) {
                x /= j;
                map[j]++;
            }
            if (x <= 1) break;
        }
    }
}

bool compare(const pair<int, int> &a, const pair<int, int> &b) {
    return a.second < b.second;
}

int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//    cout.tie(nullptr);
//    freopen("name.in", "r", stdin);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w+", stdout);

    int n, l;
    cin >> n >> l;
    vector<int> primes;
    genereatePrimes(primes, l);
    map<int, int> a, b;
    readArray(n, primes, a);
    readArray(n, primes, b);
    int mina, minb;
    minb = std::min_element(b.begin(), b.end(), compare)->second;
    mina = std::min_element(a.begin(), a.end(), compare)->second;
    if (mina <= minb)
        cout << "Rami";
    else cout << "Yassine";

    return 0;
}
