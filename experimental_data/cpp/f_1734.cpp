#include <bits/stdc++.h>

using namespace std;

using ll = long long;



#ifdef DEBUG

#include "debug.h"

#else

#define debug(...) ;

#endif



#define all(x) begin(x), end(x)

#define rall(x) rbegin(x), rend(x)

#define each(a, x) for(auto& a : (x))



#define rep(i, n) for (int i = 0; i < (n); ++i)

#define repp(i, n, m) for (int i = (n); i < (m); ++i)



#define repr(i, n) for (int i = (n) - 1; i >= 0; --i)

#define reppr(i, n, m) for (int i = (m) - 1; i >= (n); --i)



#define sz(x) int(x.size())



using vi = vector<int>;

using vvi = vector<vi>;

using vll = vector<ll>;

using pi = pair<int, int>;

using pll = pair<ll, ll>;



template <typename T, typename V> void mini(T& a, V b) {if (b < a) a = b; }

template <typename T, typename V> void maxi(T& a, V b) {if (b > a) a = b; }



bool thue(ll pos) {

    return __builtin_popcountll(pos) & 1;

    ll ret = 0;



    while (pos) {

        ret ^= pos;

        pos /= 2;

    }



    return ret & 1;

}



map<pll, ll> cache;

ll calc(ll len, ll offset) {

    if (!len || !offset)

        return 0;



    auto p = pair(len, offset);

    if (cache.count(p))

        return cache[p];



    ll ans = 0;

    if (len & 1) {

        len -= 1;

        ans += thue(len) != thue(offset + len);

    }

    if (!len)

        return cache[p] = ans;



    if (offset & 1)

        ans += len - calc(len/2, offset/2) - calc(len/2, offset/2+1);

    else

        ans += 2*calc(len/2, offset/2);



    return cache[p] = ans;

}



void solve() {

    ll offset, len;

    cin >> offset >> len;



    ll ans = calc(len, offset);

    cout << ans << '\n';



    debug(cache);



    cache.clear();

}



int main() {

#ifndef DEBUG

    ios_base::sync_with_stdio(false);

    cin.tie(nullptr);

#endif

    int z = 1;

    cin >> z;

    while (z--)

        solve();

    return 0;

}