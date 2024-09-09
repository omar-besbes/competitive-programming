#include <bits/stdc++.h>
using namespace std;

bool compare(pair<string, int> &a, pair<string, int> &b) {
    return a.second > b.second;
}

void inserer(vector<pair<string, int>> &friends, string &s, int m){
    if(friends.empty())
        friends.emplace_back(s,m);
    else {
//        int i = (int) friends.size() / 2, j = (int) friends.size();
//        while (i <= j) {
//            if (friends[i].first == s) {
//                friends[i].second += m;
//                return;
//            } else if(friends[i].first < s)
//                i = (i+j)/2;
//            else j = (i+j)/2;
//        }
//        friends.emplace_back(s, m);
        auto debut = friends.begin();
        while(debut < friends.end() && s != debut->first)
            debut++;
        if(debut == friends.end())
            friends.emplace_back(s, m);
        else debut->second += m;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
//    freopen("challenge.in", "r", stdin);
//    freopen("input.txt.txt", "r", stdin);
//    freopen("output.txt", "w+", stdout);

    int Q, K, spareMoney = 0;
    cin >> Q >> K;
    vector<pair<string, int>> friends;
    for (int i = 0; i < Q; ++i) {
        string  s;
        int m;
        cin >> s >> m;
//        friends.emplace_back(s, m);
        inserer(friends, s, m);
    }

    sort(friends.begin(), friends.end(), compare);
    auto debut = friends.begin();
    while(K-- && debut < friends.end()) {
        spareMoney += debut->second;
        debut++;
    }

    cout << spareMoney;

    return 0;
}