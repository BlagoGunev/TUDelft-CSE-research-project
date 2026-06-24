#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int >  P;

using ll = long long;

using ld = long double;

const ll INF = (ll)1e9 + 7;

const ll MOD = 998244353;

const ll MAX = 3 * (ll)1e5 + 15;

int dx[4] = { 1,0,-1,0 };

int dy[4] = { 0,1,0,-1 };

ll n, m, k, t, w, p, q, h, d;

ll gcd(long long a, long long b) { if (b == 0) return a; return gcd(b, a % b); }

ll lcm(long long a, long long b) { return a / gcd(a, b) * b; }



ll dp[3001][3001];



void update(ll & a, ll b) {

    a += b;

    a %= MOD;

}



int main(void) {

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    string s, t;

    cin >> s >> t;

    n = s.size(); m = t.size();

    for (int i = m-1; i < n; i++) {

        if (s[i] == t[0]) dp[i][1]++;

        if (i != m - 1 || s[i] == t[m - 1]) dp[i][0]++;

    }

    for (int i = n - 1; i >= 0; i--) {

        for (int j = 0; j <= n - i; j++) {

            if (j && (j > m || s[i] == t[j - 1])) update(dp[i][j], dp[i + 1][j - 1]);

            if (i+j+1 > m || s[i] == t[i + j]) update(dp[i][j], dp[i + 1][j]);

        }

    }

    ll ans = 0;

    for (int i = 0; i <= n; i++) update(ans, dp[0][i]);

    cout << ans << '\n';

}