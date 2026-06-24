/** written by : Aram  **/
// 7elo 3ny
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e9 + 7;
void solve ()
{
        int k , a , b ;
        cin >> k >> a >> b ;
        if (a < k && b % k != 0){
            cout << "-1" << endl ;
            return ;
        }
        if (b < k && a % k != 0){
            cout << "-1" << endl ;
            return ;
        }
        cout << (a / k) + (b / k) << endl ;
}
signed main()
{
    //long long test_cases ;
    //cin >> test_cases ;
    //while (test_cases--)
        solve() ;
    return 0;
}