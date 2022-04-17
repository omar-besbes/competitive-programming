#include <bits/stdc++.h>
using namespace std;

pair<long long,long long> divisor(long long n) {
    double x = sqrt(n);
    long long sum = 1, nDivisors = 2;
    for (int i = 2; i <= x; ++i)
        if(n%i == 0) {
            if (i != x) {
                sum += i;
                sum += n / i;
                nDivisors += 2;
            } else {
                sum += i;
                nDivisors += 1;
            }
        }
    return {sum, nDivisors};
}

void assemble(int *d, pair<long long,long long> &BSD, pair<long long,long long> &MD, int N, long long number, bool *visited) {
    bool construit = true;
    for (int i = 0; i < N; ++i) {
        if(!visited[i]) {
            number += d[i];
            visited[i] = true;
            assemble(d, BSD, MD, N, 10*number, visited);
            visited[i] = false;
            number -= d[i];
            construit = false;
        }
    }
    if(construit) {
        pair<long long,long long> temp;
        temp = divisor(number);
        if(temp.first >= BSD.second){
            if(temp.first == BSD.second)
                BSD.first = min(BSD.first, number);
            else BSD.first = number;
        }
        if(temp.second >= MD.second){
            if(temp.second == MD.second)
                MD.first = min(MD.first, number);
            else MD.first = number;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //freopen("challenge.in", "r", stdin);
    freopen("input.txt.txt", "r", stdin);
    freopen("output.txt", "w+", stdout);

    int N;
    cin >> N;
    int d[N];
    bool visited[N];
    long long number = 0;
    for (int i = 0; i < N; ++i) {
        cin >> d[i];
        number += d[i];
        number *= 10;
        visited[i] = false;
    }

    pair<long long,long long> BSD = {number, divisor(number).first}, MD = {number, divisor(number).second};
    assemble(d, BSD, MD, N, 0, visited);

    cout << MD.first << ' ' << BSD.first;

    return 0;
}