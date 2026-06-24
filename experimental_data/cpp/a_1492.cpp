#include <bits/stdc++.h>



using namespace std;



#define pb push_back

#define eb emplace_back

#define se second

#define fi first

#define el "\n"

#define ll long long

#define all(a)  a.begin(),a.end()

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#define PREC cout.precision(20);

const ll mod = 1e9 + 7, N = 2 * 1e5 + 1;



ll find(ll p, ll x) {

    ll res = p / x;

    return (res + 1) * x - p;

}



void GREEN() {

    ll p, a, b, c;

    cin >> p >> a >> b >> c;

    if (p % a == 0 || p % b == 0 || p % c == 0) {

        cout << 0 << el;

        return;

    }

    cout << min({find(p, a), find(p, b), find(p, c)}) << el;

}



int main() {

    PREC

    IOS

    int tc = 1;

    cin >> tc;

    while (tc--) {

        GREEN();

    }

}