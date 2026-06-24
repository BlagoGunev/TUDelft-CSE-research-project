#include <bits/stdc++.h>
#ifdef ONLINE_JUDGE
#define fast ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define N 1000005
#define M 100005
#else
#define fast 
#define N 105
#define M 105
#endif
#define mk(x) (1<<x) // be conscious if mask x exceeds int
#define sz(x) ((int)x.size())
#define upperdiv(a,b) (a/b + (a%b>0))
#define mp(a,b) make_pair(a, b)
#define endl '\n'
#define lowbit(x) (x&-x)

using namespace std;
typedef long long ll;
typedef double db;
const ll INF = 2e18;

/** fast read **/
template <typename T>
inline void read(T &x) {
    x = 0; T fg = 1; char ch = getchar();
    while (!isdigit(ch)) {
        if (ch == '-') fg = -1;
        ch = getchar();
    }
    while (isdigit(ch)) x = x*10+ch-'0', ch = getchar();
    x = fg * x;
}
template <typename T, typename... Args>
inline void read(T &x, Args &... args) { read(x), read(args...); }
template <typename T>
inline void write(T x) {
    int len = 0; char c[21]; if (x < 0) putchar('-'), x = -x;
    do{++len; c[len] = x%10 + '0';} while (x /= 10);
    for (int i = len; i >= 1; i--) putchar(c[i]);
}
template <typename T, typename... Args>
inline void write(T x, Args ... args) { write(x), write(args...); }
/** number theory **/
#define P 2000005
// O(P)
int prime[P+1];
void getPrime() {
    //memset(prime, 0, sizeof prime);
    for (int i = 2; i <= P; i++) {
        if (!prime[i]) prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0] && (ll)i*prime[j] <= P; j++) {
            prime[prime[j]*i] = 1;
            if (i%prime[j] == 0) break;
        }
    }
}

int n;
ll a[N];
ll f[N];
ll solve(ll fac) {
    if (fac == 1)
        return INF;
    ll res = 0, cnta = 0;
    for (int i = 1; i <= n; i++) {
        res += min(cnta, fac - cnta);
        cnta += a[i];
        cnta %= fac;
    }
    return res;
}
int main() {
    getPrime();
    cin >> n;
    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        read(a[i]);
        sum += a[i];
    }
    ll ans = INF;
    for (int i = 1; i <= prime[0] && prime[i] <= sum; i++) if (sum % prime[i] == 0) {
        ans = min(ans, solve(prime[i]));
        while (sum % prime[i] == 0) {
            sum /= prime[i];
        }
    }
    ans = min(ans, solve(sum));
    if (ans == INF)
        ans = -1;
    cout << ans << endl;
    return 0;
}
/*
4
2 5 9 18
*/