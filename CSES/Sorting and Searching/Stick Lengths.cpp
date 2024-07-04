#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    long long sum = 0;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a)
    {
        cin >> i;
        sum += i;
    }
    int avg1 = sum / n;
    int avg2 = (sum + 1) / n;

    sort(a.begin(), a.end());

    int med1 = a[n / 2];
    int med2 = a[(n + 1) / 2];

    long long ans1 = 0, ans2 = 0, ans3 = 0, ans4 = 0;
    for (auto &i : a)
    {
        ans1 += abs(i - avg1);
        ans2 += abs(i - avg2);
        ans3 += abs(i - med1);
        ans4 += abs(i - med2);
    }

    cout << min({ans1, ans2, ans3, ans4}) << "\n";
}