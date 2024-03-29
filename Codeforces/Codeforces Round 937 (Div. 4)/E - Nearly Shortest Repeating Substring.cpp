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
        string s;
        cin >> s;

        vector<int> fact;
        for (int i = 1; i * i <= n; i++)
            if (n % i == 0)
                fact.push_back(i), fact.push_back(n / i);
        sort(fact.begin(), fact.end());

        for (auto &i : fact)
        {
            int len = i, count = 0;
            // cout << len << "len" << "\n";
            for (int j = 0; j < len; j++)
            {
                map<char, int> m;
                for (int k = j; k < n; k += len)
                {
                  //  cout << s[k] << " ";
                    m[s[k]]++;
                }
                //cout << "\n";
                if (m.size() > 2)
                    count = 2;
                else if (m.size() == 2)
                {
                    auto mini = min(m.begin()->second, (++m.begin())->second);
                   // cout << "mini" << mini << "\n";
                    count += mini;
                }
            }
            if (count > 1)
                continue;
            else
            {
                cout << len << "\n";
                break;
            }
        }
    }
}