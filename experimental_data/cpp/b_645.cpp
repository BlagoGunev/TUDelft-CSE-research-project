#include <bits/stdc++.h>

#define sn string :: npos

#define o '1'



using namespace std;

typedef long long ll;



inline ll f(ll x)

{

    return (x * (x - 1)) >> 1;

}



int main()

{



    ll n, k; cin >> n >> k;

    ll ost = n - 2 * k;

    if (ost < 0)

        ost = 0;



    ll ans = f(n) - f(ost);

    cout << ans;

}