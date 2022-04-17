#include <bits/stdc++.h>
#define ID_MAX 100000
using namespace std;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("input.txt.txt", "r", stdin);
    //freopen("output.txt", "w+", stdout);

    int nbElements, element, nbChansonDifferentesMax = 0;
    cin >> nbElements;
    stack<int> sequence;
    vector<bool> chansonsRencontrees(ID_MAX);
    for (int i = 0; i < nbElements; ++i) {
        cin >> element;
        if(element == 0) {
            nbChansonDifferentesMax = max( (int) sequence.size(), nbChansonDifferentesMax);
            while(!sequence.empty()) {
                chansonsRencontrees[sequence.top() - 1] = false;
                sequence.pop();
            }
        } else if (!chansonsRencontrees[element - 1]) {
                chansonsRencontrees[element - 1] = true;
                sequence.push(element);
            }
    }

    cout << nbChansonDifferentesMax;

    return 0;
}

