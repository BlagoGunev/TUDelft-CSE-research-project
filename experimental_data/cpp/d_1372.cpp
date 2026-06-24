#include <bits/stdc++.h>

using namespace std;



#ifdef DEBUG

#include "debug.h"

#else

#define debug(x) void(37)

#endif



#define lsb(x) ((x)&(-x))

#define all(x) x.begin(),x.end()

#define setprec(n) cout << fixed << showpoint;cout << setprecision(n);

typedef long long ll;

typedef long double ld;

const ld eps = 1e-10;

const ll MOD1 = 1e9+7;//1000000007

const ll MOD2 = 998244353ll;

const ll LINF = (ll)1e18;

const int IINF = (int)1e9;

#define int ll





void solve(){

    int n;

    cin >> n;



    vector<int> arr(n);

    for(int i = 0;i < n;i++)

        cin >> arr[i];



    if(n == 1){

        cout << arr[0] << "\n";

        return;

    }



    vector<pair<int,int>> dp(n, {0, 0});

    dp[0] = {arr[0], arr[0]};

    dp[1] = {arr[1], arr[0] + arr[1]};

    for(int i = 2;i < n;i++){

        dp[i].first = dp[i-2].first + arr[i];

        dp[i].second = max(dp[i-1].first, dp[i-2].second) + arr[i];

    }



    int mx = 0;

    for(auto it:dp){

        mx = max(mx, it.first);

        mx = max(mx, it.second);

    }



    cout << mx << "\n";

}





signed main(){

    ios_base::sync_with_stdio(false); cin.tie(NULL);

    mt19937 mt(time(NULL));

    //setprec(10);



    //freopen("sleepy.in", "r", stdin);

    //freopen("in.txt", "w", stdout);



    int t = 1;

    //cin >> t;

    for(int i = 1;i <= t;i++)

        solve();



    return 0;

}