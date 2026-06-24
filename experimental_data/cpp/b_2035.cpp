#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e5 + 10 , mod = 1e9 + 7;
int n , a[N] , m;
string s , t;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);  cout.tie(0);
    int Tc;  cin >> Tc;
    while(Tc--)
    {
        cin >> n;
        if(n % 2 == 1 && n <= 3)
        {
            cout << -1 << '\n';
            continue;
        }
        if(n == 2)
        {
            cout << 66 << '\n';
            continue;
        }
        if(n % 2 == 0)
        {
            for(int i = 0 ; i < n - 2 ; i++)
                cout << 3;
            cout << 66 << '\n';
            continue;
        }
        for(int i = 0 ; i < n - 4 ; i++)
            cout << 3;
        cout << 6366 << '\n';
    }
    return 0;
}