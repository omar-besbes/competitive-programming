#include <bits/stdc++.h>

using namespace std;

void isPalindrome(vector<int> &v, int n = -1) {
   if (!(n + 1)) n = v.size();
   auto b = v.begin(), e = v.end() - 1;
   while (b <= e && *b == *e) {
      b++;
      e++;
   }
}

int main() {
   //    ios::sync_with_stdio(false);
   //    cin.tie(nullptr);
   //    cout.tie(nullptr);
   //    freopen("name.in", "r", stdin);
   //    freopen("input.txt", "r", stdin);
   //    freopen("output.txt", "w+", stdout);

   int t;
   cin >> t;
   while (t--) {
      int n;
      cin >> n;
      int a[n], sum = 0;
      for (int i = 0; i < n; ++i) {
         cin >> a[i];
         sum += a[i];
      }
      sum -= a[0] + a[n - 1];
      pair<int, int> p = {0, 0};  // first == nb pairs second == nb impairs
                                  //        bool pfiwostim = false;
      for (int i = 1; i < n - 1; ++i) {
         if (a[i]) (a[i] % 2 == 0) ? p.first++ : p.second++;
         //            if (a[i] %2 == 0 && !pfiwostim) {
         //                int j = 1;
         //                for (; j < i; ++j) {
         //                    if(a[i] %2 == 1)
         //                        break;
         //                }
         //                if(j != i)
         //                    for (j = i+1; j < n-1; ++j) {
         //                        if(a[i] %2 == 1) {
         //                            pfiwostim = true;
         //                            break;
         //                        }
         //                    }
         //            }
      }
      if (p.second == 0)
         cout << sum / 2 << "\n";
      else {
         if (p.first == 0) {
            if (n - 2 == sum || p.second == 1)
               cout << "-1\n";
            else
               cout << ceil((double)(sum - n % 2) / 2) +
                           ceil((double)p.second / 2)
                    << "\n";
         } else {
            cout << ceil((double)(sum + p.second) / 2) << "\n";
            //                if(p.second %2 == 0) {
            //                    if(pfiwostim) {
            //                        cout << ceil((double) sum/2) + p.second/2
            //                        << "\n";
            //                    } else {
            //                        cout << ceil((double) (sum - 2)/2) +
            //                        (p.second - 2)/2 + 2 << "\n";
            //                    }
            //                } else {
            //                    cout << ceil((double) (sum - 1)/2) + (p.second
            //                    - 1)/2 + 1 << "\n";
            //                }
         }
      }
   }

   return 0;
}