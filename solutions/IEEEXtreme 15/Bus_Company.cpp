#include <bits/stdc++.h>
using namespace std;

pair<bool, int> findPath(vector<int> &between, int root, int destination, pair<vector<int>, pair<int, int>> R[]) {
    R[root-1].second.second = true;
    if(root == destination)
        return {true, 0};

    for(int i=0; i<R[root-1].first.size(); i++) {
        pair<bool, int> x;
        if(R[i].second.second == false) {
            x = findPath(between, R[root - 1].first[i], destination, R);
            if (x.first) {
                between.push_back(root);
                R[root-1].second.second = false;
                return {true, 1 + x.second};
            }
        }
    }
    return {false, 0};
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("pack.in", "r", stdin);
    freopen("input.txt.txt", "r", stdin);

    int N;
    cin >> N;
    pair< vector<int>, pair<int, int>> R[N];
    for(int i=0; i<N; i++) {
        cin >> R[i].second.first;
        R[i].second.second = false;
    }
    for(int i=0; i<N-1; i++) {
        int a, b;
        cin >> a >> b;
        R[a-1].first.push_back(b);
        R[b-1].first.push_back(a);
    }

    int Q;
    cin >> Q;
    for(int i=0; i<Q; i++) {
        int x, u , v;
        cin >> x;
        if(x == 2) {
            cin >> u >> v;
            vector<int> between;
            findPath(between, u, v, R);
            between.pop_back();
            int score[2] = {0, 0};
            for(int j=0; j<N; j++)
                for(int k=j+1; k<N; k++)
                    if(R[j].second.first == R[k].second.first) {
                        bool test = true;
                        for(int h : between)
                            if(j+1 == h || k+1 == h) {
                                test = false;
                                break;
                            }
                        if(test)
                            score[R[j].second.first] += findPath(between, j+1, k+1, R).second;
                    }
            if(score[0] > score[1])
                cout << "A" << '\n';
            else if(score[0] < score[1])
                cout << "B" << '\n';
            else cout << "TIE" << '\n';
        }
        else {
            cin >> u;
            R[u-1].second.first = 1 - R[u-1].second.first;
        }
    }

    return 0;
}

