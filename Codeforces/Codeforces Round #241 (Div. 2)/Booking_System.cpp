#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
//    freopen("challenge.in", "r", stdin);
//    freopen("input.txt.txt", "r", stdin);
//    freopen("output.txt", "w+", stdout);

    int m, s, totalMoney = 0;
    cin >> m;
    vector<pair<pair<int, int>, int>> Request(m);
    for (int i = 0; i < m; ++i) {
        cin >> Request[i].first.second >> Request[i].first.first;
        Request[i].second = i+1;
    }
    cin >> s;
    vector<pair<int, int>> Table(s), RequestAccepted;
    for (int i = 0; i < s; ++i) {
        cin >> Table[i].first;
        Table[i].second = i+1;
    }

    while (!Table.empty() && !Request.empty()) {
        sort(Request.begin(), Request.end());
        sort(Table.begin(), Table.end());
        if(Request.back().first.first > Table.back().first) {
            Request.pop_back();
        } else {
            int pos = (int) Table.size();
            while ((Table.begin() + pos)->first >= Request.back().first.first)
                pos--;

        }
    }



    return 0;
}