#include <bits/stdc++.h>
using namespace std;

void rotateCC(pair<int, int> &pivot, pair<int, pair<int, int>> &point) {
    pair<int, int> c1 = {pivot.first - point.second.first, pivot.second - point.second.second};
    pair<int, int> c2 = {c1.second, -c1.first};
    pair<int, int> c3 = {c1.first + c2.first, c1.second + c2.second};
    point.second = {point.second.first + c3.first, point.second.second + c3.second};
    point.first++;
    point.first %= 4;
}

void symetric(pair<int, int> &origin, pair<int, pair<int, int>> &point) {
    point.second = {2*origin.first - point.second.first, 2*origin.second - point.second.second};
    point.first += 2;
    point.first %= 4;
}

double distance(pair<int, int> &p1, pair<int, int> &p2) {
    return sqrt(pow(p1.first-p2.first, 2) + pow(p1.second-p2.second, 2));
}

bool orthogonaux(pair<int, int> &p1, pair<int, int> &p2, pair<int, int> &p3) {
    return !((p2.first - p1.first)*(p3.first - p1.first) + (p2.second - p1.second)*(p3.second - p1.second));
}

bool isSquare(pair<int, pair<int, int>> point[4]) {
    if( orthogonaux(point[0].second, point[1].second, point[2].second) &&
        orthogonaux(point[1].second, point[0].second, point[3].second) &&
        orthogonaux(point[2].second, point[0].second, point[3].second) &&
        distance(point[0].second, point[1].second) != 0 &&
        distance(point[0].second, point[1].second) == distance(point[0].second, point[2].second) )
        return true;
    if( orthogonaux(point[0].second, point[1].second, point[3].second) &&
        orthogonaux(point[1].second, point[0].second, point[2].second) &&
        orthogonaux(point[3].second, point[0].second, point[2].second) &&
        distance(point[0].second, point[1].second) != 0 &&
        distance(point[0].second, point[1].second) == distance(point[0].second, point[3].second) )
        return true;
    if( orthogonaux(point[0].second, point[2].second, point[3].second) &&
        orthogonaux(point[2].second, point[0].second, point[1].second) &&
        orthogonaux(point[3].second, point[0].second, point[1].second) &&
        distance(point[0].second, point[2].second) != 0 &&
        distance(point[0].second, point[2].second) == distance(point[0].second, point[3].second) )
        return true;
    return false;
}

struct regiment{
    pair<int, pair<int, int>> point[4];
    pair<int, int> home[4];
    int nbMoves = -1;
    void calculMoves() {
        int n = 0;
        for (auto & i : point)
            n += i.first;
        if(nbMoves == -1) nbMoves = n;
        else nbMoves = min(nbMoves, n);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
//    freopen("challenge.in", "r", stdin);
    freopen("input.txt.txt", "r", stdin);
    freopen("output.txt", "w+", stdout);

//    pair<int, int> p1 = {1, 3};
//    pair<int, pair<int, int>> p2 ={0, {-1, 4}};
//    rotateCC(p1, p2);
//    cout << p2.second.first << ' ' << p2.second.second << '\n';

    int n;
    cin >> n;
    struct regiment R[n];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 4; ++j) {
            cin >> R[i].point[j].second.first >> R[i].point[j].second.second >> R[i].home[j].first >> R[i].home[j].second;
            R[i].point[j].first = 0;
        }
//        set< pair<pair<pair<int, int>, pair<int, int>>, pair<pair<int, int>, pair<int, int>>> > s;
        for (int j = 0; j < 4; ++j) {
            for (int k = 0; k < 4; ++k) {
                for (int l = 0; l < 4; ++l) {
                    for (int m = 0; m < 4; ++m) {
//                        s.insert(make_pair(make_pair(R[i].point[0].second, R[i].point[1].second), make_pair(R[i].point[2].second, R[i].point[3].second)));
                        if(isSquare(R[i].point))
                            R[i].calculMoves();
                        rotateCC(R[i].home[3], R[i].point[3]);
                    }
                    rotateCC(R[i].home[2], R[i].point[2]);
                }
                rotateCC(R[i].home[1], R[i].point[1]);
            }
            rotateCC(R[i].home[0], R[i].point[0]);
        }
        cout << R[i].nbMoves << '\n';
//        cout << s.size()<< '\n';
    }
    return 0;
}