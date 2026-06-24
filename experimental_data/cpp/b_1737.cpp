#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define PII pair<int, int>

#define endl "\n"

const int MAX = 1e9;

const int INF = 0x3f3f3f3f;

const int MOD = 1e9 + 7;

const double eps = 1e-9;

const int N = 200010;



void solve()

{



    ll l, r;

    cin >> l >> r;

    ll sq_l = (ll)sqrtl(l), sq_r = (ll)sqrtl(r);



    ll ans = (sq_r - sq_l) * 3 + (r - sq_r * sq_r) / sq_r - (l - sq_l * sq_l) / sq_l;



    if ((l - sq_l * sq_l) % sq_l == 0)

        ans += 1;



    cout << ans << endl;

}



int main()

{

    ios::sync_with_stdio(0);

    cin.tie(0);

    cout.tie(0);

    int T = 1;

    cin >> T;

    while (T--)

        solve();

    return 0;

}