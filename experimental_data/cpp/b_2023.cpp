// IN THE NAME OF GOD
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define endl '\n'
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define fuck(x) cout<<"("<<#x<<" : "<<x<<")\n"
#define pb push_back
#define pf push_front
#define Mp make_pair
#define size(x) (ll)x.size()

const int N = 6e5 + 23, lg = 19;
ll Mod = 1e9 + 7;

ll MOD(ll a, ll mod=Mod) {a%=mod; (a<0)&&(a+=mod); return a;}
ll poww(ll a, ll b, ll mod=Mod) {
    ll res = 1;
    while(b > 0) {
        if(b%2 == 1) res = MOD(res * a, mod);
        b /= 2;
        a = MOD(a * a, mod);
    }
    return res;
}

ll t, n, a[N], b[N], dp[N], seg[2*N];
vector<int> vec[N];

void upd(int ind, ll x) {
    seg[ind] = x; ind /= 2;
    while(ind > 0) {
        seg[ind] = min(seg[2*ind], seg[2*ind+1]);
        ind /= 2;
    }
}

ll qry(int l, int r, int ind=1, int lc=1 ,int rc=(1<<lg)+1) {
    if(l >= rc || lc >= r) {
        return 1e18;
    }
    if(lc >= l && rc <= r) {
        return seg[ind];
    }

    int mid = (lc + rc)/2;
    return min(qry(l, r, 2*ind, lc, mid), qry(l, r, 2*ind+1, mid, rc));
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    cin>>t;
    while(t--) {
        cin>>n;
        for(int i=1; i<=n; i++) cin>>a[i];
        for(int i=1; i<=n; i++) {
            cin>>b[i];
            if(b[i] > i) {
                vec[b[i]].pb(i);
            }
        }

        dp[1] = 0;
        for(int i=2; i<=n; i++) {
            dp[i] = 1e18;
            for(auto it : vec[i]) {
                dp[i] = min(dp[i], qry(it, i) + a[it]);
            }
            upd(i + (1<<lg) - 1, dp[i]);
        }

        ll sum = 0, ans = 0;
        for(int i=1; i<=n; i++) {
            sum += a[i];
            ans = max(ans, sum - dp[i]);
        }

        cout<<ans<<endl;

        for(int i=1; i<=n; i++) {
            upd(i + (1<<lg) - 1, 0);
            dp[i] = 0;
            vec[i].clear();
        }
    }

    return 0;
}