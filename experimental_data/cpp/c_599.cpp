#include<bits/stdc++.h>
#define rep(i,s,t) for (ll i=(s); i<=(t); ++i)
#define dep(i,t,s) for (ll i=(t); i>=(s); --i)
#define i first
#define j second
#define pb push_back
#define qb pop_back
#define pf push_front
#define qf pop_front
#define sz(x) ll((x).size())
#define p(i) (1LL<<((i)-1))
#define w(x,i) ((x)&p(i))

using namespace std;

template<class T> inline T pr(T x) { return --x; }
template<class T> inline T nx(T x) { return ++x; }
template<class T> inline T sqr(T x) { return x*x; }

template<class T>
inline void get(T &n) {
	char c = getchar();
	while (c!='-' && (c<'0' || c>'9')) c = getchar();
	n = 0; T s = 1; if (c=='-') s = -1,c = getchar();
	while (c>='0' && c<='9') n*=10,n+=c-'0',c=getchar();
	n *= s;
}

typedef long long ll;
typedef pair<ll,ll> PII;

const ll maxn = 100010;
ll n,a[maxn],Max[maxn],Min[maxn];

int main() {
    ll i,j,k,t,tt,Test;
    get(n);
    rep(i,1,n) get(a[i]);
    Max[0] = 0; Min[n+1] = 2*ll(1e9)+1;
    rep(i,1,n) Max[i] = max(a[i],Max[i-1]);
    dep(i,n,1) Min[i] = min(a[i],Min[i+1]);
    ll cnt = 0,ans = 0;
    rep(i,1,n) {
        if (Max[i] <= Min[i+1]) ++ans;
    }
    cout<<ans<<endl;

    return 0;
}