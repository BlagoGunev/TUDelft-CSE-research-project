#include<bits/stdc++.h>



using namespace std;

using i64 = long long;



const int mod = 998244353;



void solve()

{

    int n;

    cin >> n;

    if(n <= 30){

        cout << "NO\n";

        return;

    }

    if(n == 36 || n == 40 || n == 44){

        cout << "YES\n";

        cout << "6 10 15 " << n - 31 << '\n';

        return;

    }

    cout << "YES\n";

    cout << "6 10 14 " << n - 30 << '\n';

}



int32_t main()

{

    ios::sync_with_stdio(false);

    cin.tie(nullptr);

    int t = 1;

    cin >> t;

    while(t -- )solve();

    return 0;

}