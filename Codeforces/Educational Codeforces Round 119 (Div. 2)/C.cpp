#include <bits/stdc++.h>

using namespace std;

string gen(long long n) {
    string string1;
    while (n--)
        string1 += 'b';
    return string1;
}

int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//    cout.tie(nullptr);
//    freopen("name.in", "r", stdin);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w+", stdout);

    int t;
    cin >> t;
    while (t--) {
        long long n, k, x;
        cin >> n >> k >> x;
        x--;
        string string1;
        cin >> string1;
        vector<pair<long long, long long>> weights;
        for (int i = 0; i < string1.length(); ++i) {
            if(string1[i] == '*') {
                weights.emplace_back(1, i);
                while (string1[i] == '*') {
                    weights.back().first += k;
                    string1.erase(string1.begin()+i);
                }
            }
        }
        for (auto i = weights.end()-1; i >= weights.begin() ; --i) {
            long long y = i->first;
            i->first = x % y;
            x /= y;
            string1.insert(i->second, gen(i->first));
        }
        cout << string1 << '\n';
    }

    return 0;
}