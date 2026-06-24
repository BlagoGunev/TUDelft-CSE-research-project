#include <bits/stdc++.h>

#define rep(i, l, r) for(int i = (l); i <= (r); i++)

#define per(i, r, l) for(int i = (r); i >= (l); i--)

#define mem(a, b) memset(a, b, sizeof a)

#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)

#define pb push_back

#define eb emplace_back

#define SZ(x) int((x).size())

#define all(x) (x).begin(), (x).end()



using namespace std;

using ll = long long;



const int N = 1e6 + 8, P = 998244353;



int fac[N], ifac[N];



ll Pow(ll a, int n, ll r = 1) {

    for(; n; n >>= 1, a = a * a % P)

        if(n & 1) r = r * a % P;

    return r;

}

inline void inc(int& a, int b) {

    if((a += b) >= P) a -= P;

}

inline void dec(int& a, int b) {

    if((a -= b) < 0) a += P;

}

int main() {

    cin.tie(0)->sync_with_stdio(0);

    int n, K;

    cin >> n >> K;  

    if(n == K) cout << 1 << '\n', exit(0);

    fac[0] = 1;

    rep(i, 1, K) fac[i] = (ll)fac[i - 1] * i % P;

    ifac[K] = Pow(fac[K], P - 2);

    per(i, K, 1) ifac[i - 1] = (ll)ifac[i] * i % P;

    int ans = 0, ls = 0;

    rep(i, 0, K) swap(ans, ls), inc(ans, ls + 1);

    int sum = ls = 0;

    rep(i, 0, K * 2 - n) {

        swap(sum, ls), inc(sum, ls);

        if(~i & 1) sum = (sum + (ll)fac[n - K - 1 + (i >> 1)] * ifac[i >> 1] % P * ifac[n - K - 1]) % P;

        dec(ans, sum);

    }

    for(int i = n & 1; i <= K; i += 2) {

        int j = K - i - (n - i >> 1);

        if(0 <= j && j * 2 < K - i)

            ans = (ans + (ll)fac[K - i - 1 - j] * ifac[K - i - 1 - j * 2] % P * ifac[j]) % P;

    }

    cout << ans << '\n';

}