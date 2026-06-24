#include <bits/stdc++.h>

typedef long long ll;

typedef unsigned long long ull;

#define int long long

#define endl '\n'

using namespace std;

const int N = 1e6 + 5;

const int inf = 1e18;

double PI = acos(-1);

void solve()

{

    double n;

        double angle,ans;

        scanf("%lf",&n);

        angle=PI/n;

        ans=1.0/sin(angle/2.0)*cos(angle/4);

        printf("%.7f\n",ans);

}

signed main()

{

  

    int t = 1;

    cin >> t;

    while (t--)

    {

        solve();

    }

    return 0;

}