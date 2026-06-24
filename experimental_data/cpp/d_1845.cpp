#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll maxN = 2e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9 + 7;


int main() {

#ifndef ONLINE_JUDGE
   freopen("../input.txt", "r", stdin);
   freopen("../output.txt", "w", stdout);
#endif
    ll t;
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;

        vector<ll> v(n);

        for(ll & i : v) cin >> i;

        ll maxi = 0, cur = -1,ki = 0, sum = 0;

        vector<ll> suf(n+1, 0);
        for(ll i = n-1; i >= 0; i--) suf[i] = suf[i+1] + v[i];

        for(ll i = 0; i <= n; i++) {
            if(maxi + suf[i] > cur) {
                ki = maxi;
                cur = maxi + suf[i];
            }
            if(i < n)sum += v[i];
            maxi = max(maxi, sum);
        }

        cout << ki << endl;
    }
    return 0;
}