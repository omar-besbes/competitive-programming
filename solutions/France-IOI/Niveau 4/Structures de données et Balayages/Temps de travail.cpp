#include <bits/stdc++.h>
using namespace std;

bool comparer(pair<int, int> &a, pair<int, int> &b)
{
    if (a.first == b.first)
        return a.second < b.second;
    return a.first < b.first;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long long N, duration = 0, finSegment;
    cin >> N;
    vector<pair<int, int>> I(N);
    auto pos = I.begin();
    while (pos < I.end())
    {
        cin >> pos->first >> pos->second;
        pos++;
    }
    sort(I.begin(), I.end(), comparer);

    pos = I.begin();
    finSegment = pos->second;
    duration = pos->second - pos->first;
    pos++;
    while (pos < I.end())
    {
        if (pos->second <= finSegment)
        {
            pos++;
        }
        else if (pos->first <= finSegment)
        {
            duration += pos->second - finSegment;
            finSegment = pos->second;
            pos++;
        }
        else
        {
            duration += pos->second - pos->first;
            finSegment = pos->second;
            pos++;
        }
    }
    cout << duration;

    return 0;
}