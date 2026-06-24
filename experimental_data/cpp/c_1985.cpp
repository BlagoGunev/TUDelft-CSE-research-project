// powered by https://www.youtube.com/watch?v=10XYO8jr6S4

#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
// #pragma GCC optimize("O3")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;

#ifdef roflan_debug
    #include "debug.h"
#else
    #define dbg(...) 2007
#endif

typedef long long ll;
#define int ll

const bool MNOGO = true;

void letsgooooo(signed tc = 0) {
    int n;
    cin >> n;
    int a[n];
    for (auto &x : a)
    	cin >> x;
    int sum = 0;
    map <int, int> m;
    int ans = 0;
    for (int i = 0; i < n; i++) {
    	sum += a[i];
    	++m[a[i]];
    	if (sum % 2 == 0 and m[sum / 2])
    		ans += 1;
    }
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    signed tt = 1;
    if (MNOGO) cin >> tt;

    for (signed i = 1; i <= tt; i++) {
        dbg("===========", i, "===========");
        letsgooooo(i);
        dbg("=============================");
    }
}