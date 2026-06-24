#ifdef AVEVAD
#define _GLIBCXX_DEBUG
#else
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#endif

#include <bits/stdc++.h>

#define LC(V) ((V)*2+1)
#define RC(V) ((V)*2+2)

using namespace std;
using ll = long long;
using ld = long double;

const ll KEK[]{0, 2, 3, 1};

ll calc(ll a0) { return (a0 == 1) ? 2ll : KEK[a0 & 3] | calc(a0 >> 2) << 2; }

int main() {
#ifndef AVEVAD
    cin.tie(0);
    ios_base::sync_with_stdio(0);
#endif
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        ll p = 1;
        while (p <= n) p <<= 2;
        p >>= 2;
        ll a0 = p | ((n - p) / 3);
        ll a1 = calc(a0);
        ll a[]{a0, a1, a0 ^ a1};
        cout << a[(n - p) % 3] << '\n';
    }
}