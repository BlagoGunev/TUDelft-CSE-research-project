#include<bits/stdc++.h>
#define all(a) a.begin(),a.end()
#define rev(a) a.rbegin(),a.rend()
#define endl '\n'

using namespace std;
typedef long long ll;
const ll N = 1000000007;
const ll INF = 1000000000000000000;

ll pw(ll a, ll b) {
    return ll(round(pow(a, b)));
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m, x; cin >> n >> m >> x;
    vector<vector<ll>> a(n, vector<ll> (m, 0)), dis(n, vector<ll> (m, INF));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            char c; cin >> c;
            a[i][j] = c - '0';
        }
    }

    auto cycle_sum = [&] (ll i, ll j) {
        ll ret = 0;
        ret += pw(a[i][j] - a[i][j + 1], x);
        ret += pw(a[i][j + 1] - a[i + 1][j + 1], x);
        ret += pw(a[i + 1][j + 1] - a[i + 1][j], x);
        ret += pw(a[i + 1][j] - a[i][j], x);

        return ret;
    };

    bool flag = 0;
    for(int i = 0; i + 1 < n; i++) {
        for(int j = 0; j + 1 < m; j++) {
            flag |= cycle_sum(i, j) != 0;
        }
    }

    dis[0][0] = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(i) dis[i][j] = min(dis[i][j], dis[i - 1][j] + pw(a[i - 1][j] - a[i][j], x));
            if(j) dis[i][j] = min(dis[i][j], dis[i][j - 1] + pw(a[i][j - 1] - a[i][j], x));
        }
    }

    ll q; cin >> q;
    while(q--) {
        ll r1, c1, r2, c2; cin >> r1 >> c1 >> r2 >> c2;
        if(flag) {
            cout << "INVALID\n";
            continue;
        }

        --r1, --c1, --r2, --c2;
        cout << dis[r2][c2] - dis[r1][c1] << endl;
    }


    return 0;
}