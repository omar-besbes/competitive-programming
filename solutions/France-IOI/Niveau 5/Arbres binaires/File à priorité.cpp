#include "bits/stdc++.h"

using namespace std;

int q;
vector<int> t{INT_MAX};

void print()
{
    cout << "p ";
    for (int i = 1; i < t.size(); i++)
        cout << t[i] << " ";
    cout << "\n";
}

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
            t.push_back(value);
            int index = t.size() - 1;
            while (index > 1 && t[index] < t[index / 2])
            {
                swap(t[index], t[index / 2]);
                index /= 2;
            }
        }
        else
        {
            if (t.size() > 1)
            {
                cout << t[1] << "\n";
                int index = 1;
                t[index] = t.back();
                t.pop_back();
                while (2 * index < t.size())
                {
                    if (2 * index + 1 < t.size())
                    {
                        if (t[2 * index] < t[2 * index + 1])
                        {
                            if (t[index] < t[2 * index])
                                break;
                            else
                                swap(t[index], t[2 * index]), index = 2 * index;
                        }
                        else
                        {
                            if (t[index] < t[2 * index + 1])
                                break;
                            else
                                swap(t[index], t[2 * index + 1]), index = 2 * index + 1;
                        }
                    }
                    else
                    {
                        if (t[index] < t[2 * index])
                            break;
                        else
                            swap(t[index], t[2 * index]), index = 2 * index;
                    }
                }
            }
            else
            {
                cout << "-\n";
            }
        }
    }
}