#include"bits/stdc++.h"

//#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")

using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pii;
typedef vector<ll> d1;
typedef vector<d1> d2;
typedef vector<pii> d1p;
typedef vector<d1p> d2p;

ostream& operator<<(ostream&cout, const pii&a){cout<<a.first<<","<<a.second;return cout;}
template<typename T> T max(vector<T> &a){return *max_element(a.begin(), a.end());}
template<typename T> T min(vector<T> &a){return *min_element(a.begin(), a.end());}
template<typename T> T sum(vector<T>&a){T m=0;for(T&i:a)m+=i;return m;}
template<typename T> void print(vector<T>&a){for(T&i:a)cout<<i<<" ";cout<<"\n";}
template<typename T> void print(vector<vector<T>>&a){for(vector<T>&i:a)print(i);}

#define stuff ios::sync_with_stdio(false);cin.tie(nullptr);
#define fin(in) freopen(in, "r", stdin);
#define fout(out) freopen(out, "w", stdout);
#define fori(x, n) for(ll i=x;i<(ll)n;++i)
#define forj(x, n) for(ll j=x;j<(ll)n;++j)
#define fork(x, n) for(ll k=x;k<(ll)n;++k)
#define foru(p, t) for(ll i=p;i<(ll)t.size();i+=i&-i)
#define ford(r, t) for(ll i=r;i>0;i-=i&-i)
#define all(a) a.begin(),a.end()
#define sort(a) sort(all(a))
#define reverse(a) reverse(all(a))
#define unique(a) a.erase(unique(all(a)),a.end());
#define wt ll qwertyuiop;cin>>qwertyuiop;while(qwertyuiop--)
#define vec vector
#define pb push_back
#define pob pop_back
#define endl "\n"
#define F first
#define S second
#define B back()

d1 t;

ll get(ll v, ll ql, ll qr, ll l, ll r) {
    if (ql > r || l > qr){
        return 1e9;
    }
    if (ql <= l && r <= qr) {
        return t[v];
    }
    ll m = (l + r) / 2;
    ll res1 = get(v * 2, ql, qr, l, m);
    ll res2 = get(v * 2 + 1, ql, qr, m+1, r);
    return min(res1, res2);
}

void upd(ll v, ll l, ll r, ll pos, ll x) {
    if (l == r) {
        t[v] = min(t[v], x);
        return;
    }
    ll m = (l + r) / 2;
    if (pos <= m) {
        upd(2 * v, l, m, pos, x);
    }
    else {
        upd(2 * v + 1, m + 1, r, pos, x);
    }
    t[v] = min(t[2 * v], t[2 * v + 1]);
}

signed main(){
    stuff;
    ll n, q;
    cin >> n >> q;
    t.assign(4*n, 1e9);
    set<ll> s;
    fori(0, n) s.insert(i);
    while(q--){
        ll type;
        cin >> type;
        if(type==0){
            ll l, r, x;
            cin >> l >> r >> x;
            l--, r--;
            if(!x) {
                d1 del;
                auto j = s.lower_bound(l);
                while(j!=s.end() and *j <= r) {
                    del.pb(*j);
                    j++;
                }
                for(ll i: del) s.erase(i);
            }
            else{
                upd(1, 0, n-1, l, r);
            }
        }
        else{
            ll p;
            cin >> p;
            p--;
            if(s.count(p)){
                auto j = s.find(p);
                ll l = 0, r = n-1;
                if(j != s.begin()){
                    l = *(--j)+1;
                    j++;
                }
                j++;
                if(j != s.end()){
                    r = *j-1;
                    j--;
                }
                ll x = get(1, l, p, 0, n-1);
                if(x<=r){
                    cout << "YES" << endl;
                }
                else{
                    cout << "N/A" << endl;
                }
            }
            else{
                cout << "NO" << endl;
            }
        }
    }
}