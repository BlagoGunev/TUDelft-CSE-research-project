#include<bits/stdc++.h>

using namespace std;



#define _ 0

#define pll pair<int, int>

#define ll long long

#define int long long

#define endl '\n'

const int N = 2e5 + 10;

const int inf = 0x3f3f3f3f;

const int mod = 1e9 + 7;

const double eps = 1e-8;

const double pi = 3.1415926;

//const int M = 710;



int inv[N], fac[N];



int qmi(int m, int k, int p){

    int res = 1 % p, t = m;

    while (k){

        if (k&1) res = (ll)res * t % p;

        t = (ll)t * t % p;

        k >>= 1;

    }

    return res;

}



void init() {

    fac[0] = 1;

    for (int i = 1; i < N; i++) fac[i] = fac[i - 1] * i % mod;

    inv[N - 1] = qmi(fac[N - 1], mod - 2, mod);

    for (int i = N - 2; i >= 0; i--) inv[i] = inv[i + 1] * (i + 1) % mod;

} 



int C(int a, int b){

    return fac[a] * inv[b] % mod * inv[a - b] % mod;

}







void solve() {

    int n, l, r; cin >> n >> l >> r;

    int minn = min(r - n, 1ll - l), maxn = max(r - n, 1ll - l);

    int ans = C(n, n / 2) * minn % mod * (1ll + n % 2) % mod;

    for (int i = 1; i <= min(n / 2, maxn - minn); i++) {

        ans = (ans + C(n - i, n / 2)) % mod;

        if (n & 1) ans = (ans + C(n - i, n / 2 + 1ll)) % mod;

    }

    for (int i = maxn - minn + 1; i <= n / 2; i++) {

        ans = (ans + C(n - i - (i - maxn + minn), n / 2 - (i - maxn + minn))) % mod;

        if (n & 1) ans = (ans + C(n - i - (i - maxn + minn), n / 2 + 1 - (i - maxn + minn))) % mod;

    }

    int top = n / 2 + minn;

    int v = min(r - top - n / 2, n / 2 + 1 - top - l);

    ans = (ans + max(0ll, v)) % mod;

    if(n % 2){

        v = min(r - top - n / 2 - 1, n / 2 + 2 - top - l);

        ans = (ans + max(v, 0ll)) % mod;

    }



    cout << ans << endl;

}





signed main() {

    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    init();

    int T = 1; cin >> T;

    while (T--)solve();

    return ~~(0 ^ _ ^ 0);

}