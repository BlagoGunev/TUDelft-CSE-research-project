#include <bits/stdc++.h>
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define rep(i, s, t) for(int i = (s); i <= (t); i++)
#define rev(i, t, s) for(int i = (t); i >= (s); i--)
#define lson rt << 1
#define rson rt << 1 | 1

typedef long long ll;
typedef long double lb;
typedef std::pair<int, int> pii;
typedef std::pair<ll, ll> pll;
ll gcd(ll x, ll y){
    if(x > y) std::swap(x, y);
    return y % x == 0 ? x : gcd(y % x, x);
}

int main(){
#ifndef ONLINE_JUDGE
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
#endif // ONLINE_JUDGE
    ll n, k, a, b;
    scanf("%lld%lld%lld%lld", &n, &k, &a, &b);
    ll ans = (n - 1) * a;
    if(k == 1) return !printf("%lld\n", ans);
    ll tans = 0;
    while(n > 1){
        ll nn = n / k * k;
        tans += (n - nn) * a;
        if(nn > 0) tans += b;
        ll rest = 0;
        if(n / k > 1) rest += (n / k - 1) * a;
        ans = min(ans, tans + rest);
        n /= k;
    }
    printf("%lld\n", ans);
    return 0;
}