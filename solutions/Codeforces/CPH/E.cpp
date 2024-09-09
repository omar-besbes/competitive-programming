#include <bits/stdc++.h>

using namespace std;

int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//    cout.tie(nullptr);
//    freopen("name.in", "r", stdin);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w+", stdout);

    long long x, y, m, op = 0;
    cin >> x >> y >> m;
    if(x+y <= 0 && x < m && y < m) {
        if(x+y || x==0) {
            cout << -1;
            return 0;
        }
    }

    if(x*y <= 0) {
        if(x > y)
            swap(x, y);
        x *= -1;
        op += x/y;
        x %= y;
        x *= -1;
    }

    while(x < m && y < m) {
        if(x > y)
            swap(x, y);
        x = x+y;
        op++;
    }

    cout << op;

    return 0;
}

//#include<bits/stdc++.h>
//#pragma GCC target ("avx2")
//#pragma GCC optimization ("O3")
//#pragma GCC optimization ("unroll-loops")
//#define eps 1e-9
//#define MOD1 998244353
//#define MOD2 1000000007
//#define INV_2 499122177
//#define INF 1000000000
//#define PI 3.14159265358979323846
//
//using namespace std;
//
//int main()
//{
//    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
//    long long a, b, m, nb=0;
//    cin >> a >> b >> m;
//    if(a > b)
//        swap(a, b);
//    if((a >= m )||(b >= m))
//    {
//        cout << "0\n";
//        return 0;
//    }
//    if(a <= 0 && b <= 0 && m >= b)
//    {
//        cout << "-1\n";
//        return 0;
//    }
//    if(a== 0 && b==0)
//    {
//        cout << "-1\n";
//        return 0;
//    }
//    if(a <= 0 && b >= 0)
//    {
//        a*=(-1LL);
//        nb+=(a/b);
//        a%=b;
//        a*=(-1LL);
//        //cout << a << '\n';
//    }
//    long long cu=0;
//    while(a < m && b < m)
//    {
//        if(a < b)
//            a+=b;
//        else
//            b+=a;
//        nb++;
//        cu++;
//    }
//    //if(cu ==  100000000)
//    //	nb=-1;
//    cout << nb << '\n';
//}
//// size
//// 07-02-46