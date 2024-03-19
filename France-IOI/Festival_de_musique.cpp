#include <bits/stdc++.h>
#define NB_GROUPES_MAX 100000
using namespace std;

deque<int> sequence;
bool isNotNull(int a) {return a!=0 ;}

void getFirstSequence(vector<int> &Groupes, int *i) {
    int x;
    while( !all_of(Groupes.begin(), Groupes.end(), isNotNull) ) {
        cin >> x;
        Groupes[x-1]++;
        sequence.push_back(x);
        (*i)++;
    }
}

void simplify(vector<int> &Groupes) {
    if(Groupes.empty()) return;
    while(Groupes[sequence.front() - 1] > 1) {
        Groupes[sequence.front() - 1]--;
        sequence.pop_front();
    }
}

void advance(vector<int> &Groupes, int *i) {
    int x;
    cin >> x;
    Groupes[x-1]++;
    Groupes[sequence.front()-1]--;
    sequence.pop_front();
    sequence.push_back(x);
    (*i)++;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("input.txt.txt", "r", stdin);
    freopen("output.txt", "w+", stdout);

    int nbJ, nbG, i = 0;
    cin >> nbJ >> nbG;
    vector<int> Groupes(nbG);
    getFirstSequence(Groupes, &i);
    simplify(Groupes);
    int mini = min(nbJ, (int) sequence.size());

    while(i < nbJ) {
        advance(Groupes, &i);
        while(i < nbJ && !all_of(Groupes.begin(), Groupes.end(), isNotNull)) {
            advance(Groupes, &i);
        }
        if(i < nbJ) {
            simplify(Groupes);
            mini = min(mini, (int) sequence.size());
        }
    }
    cout << mini;

    return 0;
}