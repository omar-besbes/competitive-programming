#include "bits/stdc++.h"

using namespace std;

#define N (int)4 * 1e5

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (c != a + 1)
        {
            cout << "-1\n";
            continue;
        }

        int currEmpty = 1, nextEmpty = 0, res = 0;
        while (a--)
        {
            if (currEmpty == 0)
            {
                swap(currEmpty, nextEmpty);
                res++;
            }
            currEmpty--;
            nextEmpty += 2;
        }

        while (b--)
        {
            if (currEmpty == 0)
            {
                swap(currEmpty, nextEmpty);
                res++;
            }
            currEmpty--;
            nextEmpty++;
        }

        if (currEmpty == 0)
        {
            swap(currEmpty, nextEmpty);
            res++;
        }

        if (nextEmpty)
            res++;

        cout << res << "\n";
    }
}