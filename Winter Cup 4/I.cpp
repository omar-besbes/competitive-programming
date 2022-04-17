#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int> >sieve[1000005];

void init()
{

    for (int i = 2; i <= 1000000; ++i){
        if(sieve[i].empty())
            for (int j = i; j <= 1000000; j+=i)
                sieve[i].push_back(make_pair(i, 0));
        int x=i;
        for (int j = 0; j <= sieve[i].size(); ++j) {
            xhile(x%sieve[i][j].first)
            {
                x/=sieve[i][j].first;
                sieve[i][j].second++;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
//    freopen("name.in", "r", stdin);
 //   freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w+", stdout);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int a[n];
        int nb=0;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int j=n;
        for (int i = 1; i < n; ++i) {
            if(a[i] > a[i-1]){
                j=i;
                break;
            }
        }
        nb=n-j;
        cout << nb << '\n';
    }


    return 0;
}