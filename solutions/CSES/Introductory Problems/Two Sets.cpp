#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, sum;
    cin >> n;
    sum = n * (n + 1) / 2;
    if (sum & 1)
        cout << "NO\n";
    else if (n % 4 == 0)
    {
        cout << "YES\n";
        cout << n / 2 << "\n";
        for (int i = 1; i <= n / 2; i += 2)
            cout << i << " " << n - i + 1 << " ";
        cout << "\n";
        cout << n / 2 << "\n";
        for (int i = 2; i <= n / 2; i += 2)
            cout << i << " " << n - i + 1 << " ";
        cout << "\n";
    }
    else
    {
        cout << "YES\n";
        cout << (n + 1) / 2 << "\n";
        for (int i = 1; i <= n / 2; i += 2)
            cout << i << " " << n - i << " ";
        cout << "\n";
        cout << n / 2 << "\n";
        for (int i = 2; i <= n / 2; i += 2)
            cout << i << " " << n - i << " ";
        cout << n << " " << "\n";
    }

    return 0;
}
