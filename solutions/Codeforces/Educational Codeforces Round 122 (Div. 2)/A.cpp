#include <bits/stdc++.h>

using namespace std;

int numberOfSameDigits(int a, int b) {
    if(b > a)
        swap(a, b);
    int d = 1, result = 0;
    while((a/d)%(10*d)) {
        if((a/d)%(10*d) == (b/d)%(10*d))
            result++;
        d *= 10;
    }
    return result;
}

int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//    cout.tie(nullptr);
//    freopen("name.in", "r", stdin);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w+", stdout);

    vector<int> two, three;
    for (int i = 2; i <= 14; ++i) {
        two.push_back(i*7);
    }
    for (int i = 15; 7*i < 1000; ++i) {
        three.push_back(7*i);
    }

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if(n%7 != 0) {
            if(n/100) {
                int nouv = three[0], op = numberOfSameDigits(nouv, n);
                for (auto i:three) {
                    int x = numberOfSameDigits(n, i);
                    if(x > op) {
                        nouv = i;
                        op = x;
                    }
                }
                n = nouv;
            } else {
                int nouv = two[0], op = numberOfSameDigits(nouv, n);
                for (auto i:two) {
                    int x = numberOfSameDigits(n, i);
                    if(x > op) {
                        nouv = i;
                        op = x;
                    }
                }
                n = nouv;
            }
        }
        cout << n << '\n';
    }

    return 0;
}