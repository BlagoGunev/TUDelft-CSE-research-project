/*

Author: Mohanned Ahmed

*/



#include<bits/stdc++.h>

#define ll long long

#define pb(x) push_back(x)

#define ar array

#define FOR(N) for(int i = 1; i <= N; ++i)

using namespace std;

const int N = 2e5 + 5, M = 1e9 + 7;

int dp[N] = {};



ll n, m, a, b, c, k;



int main(){

    ios_base::sync_with_stdio(false);

    cin.tie(0);

    cout.tie(0);

    int t;

    cin >> t;

    while(t--){

        cin >> a >> b >> c;

        ll ans = 0;

        ans += a;

        ans += b*2;

        ans += c*3;

        cout << ans%2 << '\n';

    }

}