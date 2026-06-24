#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define debug(x...)
#endif

// #define int int64_t
#define ll long long
#define nl "\n"
#define FOR(i,b,c) for (int i = b; i < c; i++)
 
const int32_t MAXN = 4e6+1;
const int32_t eps = 1e-6;
const int N = 2e5+1;
const int M = 27*3+2;


int runcases(int qq)
{  

    int n,q;
    cin >> n >> q;
    vector<string> v(n+1,"");
    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;
        char c;
        cin >> c;
        for (int j = 1; j <= n; j++) {
            if (j == x) {
                v[j] += c;
            }
            else {
                v[j] += '.';
            }
        }
    }

    vector<vector<int>> diff_last(n+1,vector<int>(n+1,1));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            int l1 = 1, r1 = 1, l2 = 2, r2 = 2;
            for (int k = 0; k < q; k++) {
                if (v[i][k] == '+') r1++;
                if (v[i][k] == '-') l1++;
                if (v[j][k] == '+') r2++;
                if (v[j][k] == '-') l2++;
                if (r1 == l2) l2++, r2++;
            }
            diff_last[i][j] = r2-r1;
        }
    }
    // debug(diff_last);

    vector<vector<int>> dp((1<<n),vector<int>(n,1e9+5));
    for (int i = 0; i < n; i++) {
        int l = 1, r = 1;
        for (auto c : v[i+1]) {
            if (c == '+') r++;
            if (c == '-') l++;
        }
        dp[(1<<i)][i] = r;
    }
    for (int mask = 1; mask < (1<<n); mask++) {
        if (__builtin_popcount(mask) == 1) continue;
        for (int i = 0; i < n; i++) {
            if ((1<<i)&mask) {
                int prevmask = mask^(1<<i);
                for (int j = 0; j < n; j++) {
                    if ((1<<j)&prevmask) {
                        dp[mask][i] = min(dp[mask][i],dp[prevmask][j]+diff_last[j+1][i+1]);
                    }
                }
            }
        }
    }

    int ans = 1e9+5;
    for (int i = 0; i < n; i++) {
        ans = min(ans,dp[(1<<n)-1][i]);
    }

    cout << ans << nl;
 
    return 0;
    
}

 
signed main()
{
    
    //..........Fast I/O.........//
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    //..........................//


    int t;
    t = 1;

    for (int i = 1; i <= t; i ++) {
        runcases(i);
    }
    
    return 0;
 
}