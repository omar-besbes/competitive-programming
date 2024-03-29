#include "bits/stdc++.h"
using namespace std;

int n;
vector<int> a;

void merge_sort(vector<int> &tmp)
{
    if (tmp.size() != 1)
    {
        int m = tmp.size() / 2;
        auto left = vector<int>(tmp.begin(), tmp.begin() + m);
        auto right = vector<int>(tmp.begin() + m, tmp.end());
        merge_sort(left);
        merge_sort(right);

        auto leftp = left.begin(), rightp = right.begin();
        for (auto &i : tmp)
        {
            if (leftp != left.end() && rightp != right.end())
            {
                if (*leftp < *rightp)
                    i = *leftp, leftp++;
                else
                    i = *rightp, rightp++;
            }
            else if (leftp != left.end())
            {
                i = *leftp, leftp++;
            }
            else
            {
                i = *rightp, rightp++;
            }
        }
    }
}

void print(string message, vector<int> a)
{
    cout << message;
    for (auto &i : a)
        cout << i << " ";
    cout << "\n";
}

int main()
{
    cin >> n;
    a.resize(n);
    for (auto &i : a)
        cin >> i;

    merge_sort(a);
    for (auto &i : a)
        cout << i << " ";
}