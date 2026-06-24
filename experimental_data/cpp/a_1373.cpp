#include <bits/stdc++.h>

typedef long long ll;

typedef unsigned long long ull;

#define int long long

#define endl '\n'

using namespace std;

const int N = 1e6 + 5;

const int inf = 1e18;

void solve()

{

    int a,b,c;

    cin >> a >> b >> c;

    if(a >=c)//买1个

    {

        cout << -1 << " ";

    }

    else

    {

        cout << 1 << " ";

    }

    if(c >= a*b)

    {

        cout << -1 << " ";

    }

    else

    {

        cout << b << " ";

    }

    cout << endl;



}

signed main()

{

    ios_base::sync_with_stdio(0);

    cin.tie(0);

    cout.tie(0);

    int t = 1;

    cin >> t;

    while (t--)

    {

        solve();

    }

    return 0;

}