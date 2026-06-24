/*
    IN THE NAME OF GOD
*/
#include <bits/stdc++.h>

// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma GCC optimize("O3")
// #pragma GCC optimize("unroll-loops")

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef long double ld;

#define F                                      first
#define S                                      second
#define Mp                                     make_pair
#define pb                                     push_back
#define pf                                     push_front
#define size(x)                                ((ll)x.size())
#define all(x)                                 (x).begin(),(x).end()
#define kill(x)		                           cout << x << '\n', exit(0);
#define fuck(x)                                cout << "(" << #x << " , " << x << ")" << endl
#define endl                                   '\n'

const int N = 3e5+23, lg = 18;
ll Mod = 1e9+7; //998244353;

inline ll MOD(ll a, ll mod=Mod) {a%=mod; (a<0)&&(a+=mod); return a;}
inline ll poww(ll a, ll b, ll mod=Mod) {
    ll ans = 1;
    a=MOD(a, mod);
    while (b) {
        if (b & 1) ans = MOD(ans*a, mod);
        b >>= 1;
        a = MOD(a*a, mod);
    }
    return ans;
}

ll t, n, q, a[N];
int main () {
	ios_base::sync_with_stdio(false), cin.tie(0);

	cin>>t;
    while(t--) {
        cin>>n>>q;
        set<int> st[16];
        for(int i=1; i<=n; i++) {
            char ch1, ch2; cin>>ch1>>ch2;
            if(ch1=='B') a[i] ^= 1;
            else if(ch1=='G') a[i] ^= 2;
            else if(ch1=='R') a[i] ^= 4;
            if(ch2=='Y') a[i] ^= 8;
            else if(ch2=='G') a[i] ^= 2;
            else if(ch2=='R') a[i] ^= 4;
            st[a[i]].insert(i);
        }

        for(int v,u,i=1; i<=q; i++) {
            cin>>v>>u;
            if(v > u) swap(v,u);
            if((a[v] & a[u]) > 0) {
                cout<<u - v<<endl;
                continue;
            }
            int ans = 1e9;
            for(int j=0; j<=3; j++) {
                if((a[v]>>j)%2 == 0) continue;
                for(int k=0; k<=3; k++) {
                    if((a[v]>>k)%2 == 1) continue;
                    int tmp = (a[v]^(1<<j)^(1<<k));
                    auto it = st[tmp].lower_bound(v);
                    if(it != st[tmp].end()) {
                        ans = min(ans, (*it)-v + abs(u-(*it)));
                    }
                    if(size(st[tmp])>0 && it != st[tmp].begin()) {
                        it -- ;
                        ans = min(ans, v-(*it) + abs(u-(*it)));
                    }
                }
            }
            cout<<(ans == 1e9 ? -1 : ans)<<endl;
        }

        for(int i=1; i<=n; i++) a[i]=0;
    }

	return 0;
}