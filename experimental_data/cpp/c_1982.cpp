//includes
#include <iostream>
#include <string>
#include <stack>
#include <deque>
#include <vector>
#include <set>
#include <queue>
#include <functional>
#include <algorithm>
#include <map>
#include <cstdio>
#include <cmath>
#include <random>
#include <cstdlib>
#include <unordered_map>
#include <chrono>
#include <bitset>
using namespace std;
//typedefs+usings
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;
typedef set<ll> sll;
typedef queue<ll> qll;
typedef map<ll, ll> mll;
typedef unordered_map<ll, ll> umll;
typedef pair<ll,ll> ii;
//typedef tree<pll,null_type,less<>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

//defines
#define enl "\n"
#define x first
#define y second
#define all(a) a.begin(),a.end()
#define fr(i, n) for(ll i = 0; i < n; i++)
#define rfr(i, n) for(ll i = n-1; i >= 0; i--)
#define rp(i, m, n) for(ll i = m; i < n; i++)
#define rrp(i, m, n) for(ll i = n-1; i >= m; i--)
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);

struct custom_hash {
    // better than hash on unordered
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

inline ll nxt() {
    ll x;
    cin >> x;
    return x;
}
inline void c_v(vll &a) {
    generate(all(a), nxt);
}
//Consts:

const double EPS = 1e-9;
ll YES = 4e18 + 1;
ll NO = 4e18 + 2;

struct SEG {
    ll sz;
    vector<ll> sum, pre, suf, sub;

    SEG(vector<ll> &input, ll n) {
        for (sz = 1; sz < n; sz *= 2);
        sum.resize(2 * sz);
        pre.resize(2 * sz);
        suf.resize(2 * sz);
        sub.resize(2 * sz);
        for (ll i = 0; i < n; i++) {
            sum[i + sz] = input[i];
            pre[i + sz] = suf[i + sz] = sub[i + sz] = input[i];
        }
        for (ll i = sz - 1; i; i--) {
            sum[i] = sum[2 * i] + sum[2 * i + 1];
            pre[i] = max(pre[2 * i], sum[2 * i] + pre[2 * i + 1]);
            suf[i] = max(suf[2 * i + 1], sum[2 * i + 1] + suf[2 * i]);
            sub[i] = max(sub[2 * i], sub[2 * i + 1]);
            sub[i] = max(sub[i], suf[2 * i] + pre[2 * i + 1]);
            sub[i] = max(sub[i], sum[i]);
        }
    }
    ll query(ll l, ll r) {
        vector<ll> vals;
        stack<ll> right;
        for (l += sz, r += sz; l <= r; l /= 2, r /= 2) {
            if (l % 2 == 1) vals.push_back(l++);//res=max(res,pre[l++]);
            if (r % 2 == 0) right.push(r--);//res=max(res,pre[r--]);
        }
        while (!right.empty()) {
            vals.push_back(right.top());
            right.pop();
        }
        ll msf = -4e18, meh = 0;
        for (ll ind : vals) {
            msf = max(msf, meh+pre[ind]);
            meh = max(meh+sum[ind],suf[ind]);
            msf = max(msf, meh);
            msf = max(msf, sub[ind]);
            meh = max(0ll,meh);
        }
        return msf;
    }

};

ll SUM(vll &v, ll l, ll r) {
    long long a;
    long long best = -4e18;
    long long cur = 0;
    for (ll i = l; i<=r; i++) {
        a = v[i];
        cur = max(a,cur+a);
        best = max(best,cur);
    }
    return best;
}

void doo(vll &v, ll n, vll &close) {
    stack<ii> S;
    ll num;
    for (ll i = 0; i < n; i++) {
        num = v[i];
        while (!S.empty()) {
            if (S.top().second >= num) {
                S.pop();
            } else {
                break;
            }
        }
        if (S.empty()) {
            close[i] = -1;
            S.push(ii(i, num));
        } else {
            close[i] = S.top().first;
            S.push(ii(i, num));
        }
    }
}
vll merge(vll &a, vll &b, ll n1, ll n2) {
    ll l1 = 0, l2 = 0;
    vll temp;
    while (l1 < n1 && l2 < n2) {
        if (a[l1] < b[l2]) temp.push_back(a[l1++]);
        else temp.push_back(b[l2++]);
    }
    return temp;
}
/*struct MER {
	ll sz;
	vector<ordered_set> v;

	MER(vector<ll> &input, ll n) {
		for (sz = 1; sz < n; sz *= 2);
		v.resize(2 * sz);
		for (int i = 0; i<n; ++i) v[i+sz].insert({input[i], 1});
		for (int i = sz-1; i; --i) {
			v[i] = v[2*i];
			for (pll p : v[2*i+1]) v[i].insert(p);
		}
	}
	void update(ll i, ll val) {
		ll orig = i;
		for (i += sz; i; i/=2) {
			v[i].insert({val,1});
		}
	}
	ll query(ll l, ll r, ll k) {
		vector<ll> vals;
		stack<ll> right;
		for (l += sz, r += sz; l <= r; l /= 2, r /= 2) {
			if (l % 2 == 1) vals.push_back(l++);//res=max(res,pre[l++]);
			if (r % 2 == 0) right.push(r--);//res=max(res,pre[r--]);
		}
		while (!right.empty()) {
			vals.push_back(right.top());
			right.pop();
		}
		ll ans = 0;
		for (int i : vals) {
			ans += v[i].order_of_key({k,0});
		}
		return ans;
	}

};*/
const ll MOD = 1e9+7;

ll fastPow(ll a, ll b) {
    if (b == 0) return 1;
    if (b & 1) return (a*fastPow(a,b-1))%MOD;
    return fastPow((a*a)%MOD,b/2);
}

const ll MAXN = 2e6+10;
ll fact[MAXN], ifact[MAXN];

ll prep() {
    fact[0] = 1;
    for (ll i = 1; i<MAXN; ++i) fact[i] = (fact[i-1] * i) % MOD;
    ifact[MAXN-1] = fastPow(fact[MAXN-1], MOD-2);
    for (ll i = MAXN-2; i+1; --i) ifact[i] = (ifact[i+1] * (i+1)) % MOD;
}
ll choose(ll n, ll k) {
    if (k == 0 || k == n) return 1;
    if (k == 1 || k == n-1) return n;
    return ((fact[n]*ifact[n-k]) % MOD *ifact[k]) % MOD;
}
ll place(ll space, ll candys) {
    if (candys == 0) return 1;
    if (space == 0) return 0;
    return choose(space+candys-1, space-1);
}
ll countOpts(ll avai1, ll place1, ll avai2, ll place2) {
    return (place(avai1, place1) * place(avai2, place2)) % MOD;
}
ll ans = 0,sz;
ll dfs(ll par, ll node, vvll &adj) {
    ll tot = 1;
    for (int u : adj[node]) {
        if (u == par) continue;
        ll a = dfs(node, u, adj);
        if (a >= sz) ++ans;
        else tot += a;
    }
    if (node == 0 && tot < sz) --ans;
    return tot;
}
ll solve() {
    ll n,l,r; cin >> n >> l >> r;
    vll v(n); c_v(v);
    vll pre(n+1, 0);
    for (int i = 0; i<n; ++i) {
        pre[i+1] = pre[i]+v[i];
    }
    vll ans(n+1, 0);
    ans[n-1] = v.back() >= l && v.back() <= r;
    for (int i = n-2; i >= 0; --i) {
        ans[i] = ans[i+1] + (v[i] >= l && v[i] <= r);
        if (ans[i] == ans[i+1] + 1) continue;
        int lo = i, hi = n-1;
        while (lo < hi) {
            int mid = (lo+hi)/2;
            ll sum = pre[mid+1]-pre[i];
            if (sum >= l) hi = mid;
            else lo = mid+1;
        }
        ll sum = pre[lo+1]-pre[i];
        if (sum >= l && sum <= r) ans[i] = max(ans[i], ans[lo+1]+1);
    }
    return ans[0];
}
int main() {
    fast
    ll t = 1; cin >> t;
    while (t--) {
        cout << solve() << endl;
        //solve();
        //cout << enl;
    }
}