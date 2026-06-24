//  ॐ
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ld long double
typedef pair<int,int>       pii;
typedef pair<ll,ll>       pll;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<ll>>;
#define pb              push_back 
#define Sort(a)         sort(a.begin(),a.end())
#define ff                  first
#define ss                  second 
const int N = 2e5 + 10;
const ll f = 998244353;

vvll in(N);

vll par(N,0);
ll find(ll x){
    if(par[x]==x) return x;
    else return par[x]=find(par[x]);
}

ll binpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % f;
        a = a * a % f;
        b >>= 1;
    }
    return res;
}

void solve(int test){
    ll n;
    cin >> n;
    vll ar(n+1);
    vi nx(n+1,0),od(n+1,0);
    int fl = 1;

    for(int i = 1; i < N; i++){
        par[i] = i;
    }

    set<int> st;
    for(int i = 1; i <= n; i++){
        cin >> ar[i];
        in[ar[i]].pb(i);
        st.insert(ar[i]);
    }

    ll s = binpow(2, st.size());

    for(auto &x: st){
        if(in[x].size() & 1) fl = 0;
        for(int i = 0; i < in[x].size(); i++){
            nx[in[x][i]] = in[x][i];
            if(i % 2 == 0 && (i + 1) < in[x].size()){
                nx[in[x][i]] = in[x][i + 1];
                od[in[x][i]] = 1;
            }
        }
    }

    if(!fl){
        cout << (s * binpow(2, f - 2)) % f << "\n"; return;
    }

    int cr = ar[1], en = nx[1];
    vector<int> r, b;
    for(int i = 1; i <= n; i++){
        if(en < i){
            cr = find(ar[i]); en = nx[i];
        }
        if(od[i]) b.pb(ar[i]);
        else r.pb(ar[i]);
        en = max(en, nx[i]);
        par[find(ar[i])] = cr;
    }

    for(int i = 0; i < r.size(); i++){
        if(r[i]!=b[i]) fl = 0;
    }
    if(!fl){
        cout << (s * binpow(2, f - 2)) % f << "\n"; return;
    }

    set<int> ts;
    for(auto &x: st){
        ts.insert(find(x));
    }
    ll t = binpow(2, ts.size());

    s = (s - t + f) % f;

    cout << (s * binpow(2, f - 2)) % f << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t=1;
    // cin>>t;
    for(int i = 1; i <= t; i++){
        solve(i);
    }
}