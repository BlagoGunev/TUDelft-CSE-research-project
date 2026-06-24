#include <bits/stdc++.h>



using namespace std;



#define size(x) (int)((x).size())



#define int long long



const int MOD = 1e9+7;



int dp [64][13];



void solve() {

    int x;

    cin >> x;

    // string sx = bitset<62>(x).to_string();

    // reverse(sx.begin(), sx.end());

    // while (sx.back() == '0') {

    //     sx.pop_back();

    // }

    // sx += '0';

    // reverse(sx.begin(), sx.end());

    // for (int i = 0; i < 13; i++) dp[0][i] = 0;

    // dp[0][0] = 1;

    // for (int i = 1; i < size(sx); i++) for (int j = 0; j < 13; j++) {

    //     dp[i][j] = 0;

    //     for (int k = (sx[i]-'0'+j)%2; k <= 7; k += 2) {

    //         int nj = j+k;

    //         nj /= 2;

    //         dp[i][j] += dp[i-1][(j+k)/2];

    //         dp[i][j] %= MOD;

    //     }

    // }

    int res = ((x/4LL+1LL)%MOD)*((x/2LL-x/4LL+1LL)%MOD);

    res %= MOD;

    // int res = dp[size(sx)-1][0];

    cout << res;

    cout << '\n';

}



signed main() {

    ios_base::sync_with_stdio(0);

    cin.tie(0);



    int n;

    cin >> n;

    while (n--) solve();

}