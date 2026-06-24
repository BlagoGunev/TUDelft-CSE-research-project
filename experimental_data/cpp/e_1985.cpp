#pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx,popcnt,sse4,abm")
#include <bits/stdc++.h>
using namespace std;

#ifdef WAIMAI
#define debug(HEHE...) cout << "[" << #HEHE << "] : ", dout(HEHE)
void dout() {cout << '\n';}
template<typename T, typename...U>
void dout(T t, U...u) {cout << t << (sizeof...(u) ? ", " : ""), dout(u...);}
#else
#define debug(...) 7122
#endif

#define int long long
#define ll long long
#define Waimai ios::sync_with_stdio(false), cin.tie(0)
#define FOR(x,a,b) for (int x = a, I = b; x <= I; x++)
#define pb emplace_back
#define F first
#define S second

const int SIZE = 2e5 + 5;

int x, y, z, k, ans;

void solve() {
    cin >> x >> y >> z >> k;
    ans = 0;
    FOR (i, 1, x) FOR (j, 1, y) if (k % (i * j) == 0) {
        int t = k / (i * j);
        ans = max(ans, (x - i + 1) * (y - j + 1) * (z - t + 1));
    }
    cout << ans << '\n';
}

int32_t main() {
    Waimai;
    int tt = 1;
    cin >> tt;
    while (tt--) solve();
}