#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define vi vector<int>

using namespace std;
const int MAXN = 5e5 + 1;
const int MOD = 1e9+7;
const ll LINF = 1e18+1;
const int mod = 998244353;


void solve() {
    int n, k;
    cin >> n >> k;
    int a[n+1];
    map<int, int> mp;
    for( int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        mp[x]++;
    }
    vector<int> v, w;
    for( int i = 1; i <= n; ++i) {
        if( mp[i] == 2) {
            v.pb(i);
            v.pb(i);
        }
        else if( mp[i] == 0) {
            w.pb(i);
            w.pb(i);
        }
    }
    for( int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        if( mp[x] == 1) {
            v.pb(x);
            w.pb(x);
        }
    }
    k *= 2;
    for( int i = 0; i < k; ++i) {
        cout << v[i] << " ";
    } cout << '\n';
    for( int i = 0; i < k; ++i) {
        cout << w[i] << " ";
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--) {
        solve();
    }
}