#include "bits/stdc++.h"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                for (int i = 0; i < n; i++)
                {
                    if ((i + j) % 2 == 0)
                        cout << "##";
                    else
                        cout << "..";
                }
                cout << "\n";
            }
        }
    }
}