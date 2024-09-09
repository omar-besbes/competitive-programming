#include "bits/stdc++.h"

using namespace std;

int q;
priority_queue<int, vector<int>, greater<int>> t;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> q;
    for (int i = 0; i < q; ++i)
    {
        char type;
        cin >> type;
        if (type == 'I')
        {
            int value;
            cin >> value;
            t.push(value);
        }
        else
        {
            if (!t.empty())
                cout << t.top() << "\n", t.pop();
            else
                cout << "-\n";
        }
    }
}