/*
    Created by:- milind0110
*/
// #pragma GCC optimize("O3")
// #pragma GCC target ("avx2")
// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
// #pragma GCC optimize("unroll-loops")
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include <array>
#include <climits>
// #pragma comment(linker, "/STACK:268435456");
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
using namespace std;
#define int long long
// #define double long double
// #define all(x) (x).begin(),(x).end()
// #define allr(x) (x).rbegin(),(x).rend()
// #define sz(x) (int)(x).size()
// #define pb push_back
// #define ppb pop_back
const int inf = 1e9;
void solve() {
    int n;
    cin >> n;
    vector<pair<string,string>> v(n);
    for(auto &[x,y] : v) cin >> x >> y;
    vector<vector<int>> dp(1 << n,vector<int>(n,-inf));
    for(int i = 0; i < n; i++){
        dp[1 << i][i] = 1;
    }
    vector<vector<int>> can(n,vector<int>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j) continue;
            can[i][j] = (v[i].first == v[j].first || v[i].second == v[j].second);
        }
    }
    int ans = 1;
    for(int mask = 1; mask < (1 << n); mask++){
        for(int i = 0; i < n; i++){
            if(~mask >> i & 1) continue;
            ans = max(ans,dp[mask][i]);
            for(int j = 0; j < n; j++){
                if(mask >> j & 1) continue;
                if(can[i][j]) dp[mask ^ (1 << j)][j] = max(dp[mask ^ (1 << j)][j],dp[mask][i] + 1);
            }
        }
    }
    cout << (n - ans) << "\n";
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int32_t t = 1;
    cin >> t;
    for(int32_t i = 1; i <= t; i++){
        solve();
    }
    return 0; 
}