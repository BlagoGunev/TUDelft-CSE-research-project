#include <bits/stdc++.h>

using namespace std;

#define all(a) a.begin(), a.end()
#pragma GCC optimize("", on)
#pragma GCC optimize("Ofast,03")

using ll = long long;
using ld = long double;
using umll = unordered_map<ll, ll>;
using umil = unordered_map<int, ll>;
using umii = unordered_map<int, int>;
using vll = vector<ll>;
using vvll = vector<vll>;
using pll = pair<ll, ll>;
using pii = pair<int, int>;
using vpll = vector<pll>;

using namespace std;

template<typename U, typename V>
ostream &operator<<(ostream &ost, pair<U, V> p) {
    return ost << "(" << p.first << ", " << p.second << ")";
}

template<typename T>
ostream& operator<<(ostream& ost, const vector<T>& v){
    ost<<"[";
    for(auto x : v){
        ost<<x<<" ";
    }
    return ost<<"]\n";
}

ll fpow(ll a, ll n, ll p){
    ll res = 1;
    for(; n; n >>= 1, a = a*a%p){
        if(n&1)
            res = res*a%p;
    }
    return res;
}

ll p = 1e9+7;

ll inv(ll a){
    return fpow(a, p-2, p);
}

vector<ll> fac, ifac;

void precalc(){
    int maxn = 1e5+1;
    fac.resize(maxn);
    ifac.resize(maxn);
    fac[0] = ifac[0] = 1;
    for (int i = 1; i < maxn; ++i) {
        fac[i] = i*fac[i-1]%p;
        ifac[i] = inv(fac[i]);
    }
}

ll cc(int n, int k){
    return fac[n]*ifac[k]%p*ifac[n-k]%p;
}

vector<vector<int>> pos, gep;
vector<vector<ll>> f;

void solve() {
    int n, c, m;
    cin>>n>>c>>m;
    vector<int> x(m);
    pos.assign(n, {});
    gep.assign(n, {});
    f.assign(n+1, vector(m+c, 0ll));
    for (int i = 0; i < m; ++i) {
        cin>>x[i];
        --x[i];
        if(x[i] != -1) {
            pos[x[i]].push_back(i);
            for(int j = x[i]; j >= 0; --j){
                gep[j].push_back(i);
            }
        }
    }
    f[0][0] = 1;
    for (int i = 0; i < n-1; ++i) {
        for(int cnt = 0; cnt < m; ++cnt){
            if(f[i][cnt] == 0)
                continue;
            f[i][cnt]%=p;
            int l = cnt + c - 1;
            int br = std::upper_bound(gep[i].begin(), gep[i].end(), l)-gep[i].begin();
            if(!pos[i].empty() && pos[i].back() > l)
                continue;
            int pc = pos[i].size(), t = c - br;
            for (int j = 0; j <= t; ++j) {
                f[i+1][cnt+pc+j] += f[i][cnt]*cc(t, j)%p;
            }
        }
    }
    cout<<f[n-1][m-c]%p<<"\n";
}

signed main() {
    //debug();
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    precalc();
    int n = 1;
    cin >> n;
    while (n--)
        solve();
}

/*
1
6 1 3
2 0 0

1
2 3 5
0 0 1 0 2

1
2 1 2
0 2

 */