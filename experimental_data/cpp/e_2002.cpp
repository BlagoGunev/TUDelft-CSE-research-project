#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair <ll,ll> pll;
typedef pair <int,int> pii;
typedef pair <int,pii> piii;

#define forr(_a,_b,_c) for(int _a = (_b); _a <= (_c); ++_a)
#define ford(_a,_b,_c) for(int _a = (_b) + 1; _a --> (_c);)
#define forf(_a,_b,_c) for(int _a = (_b); _a < (_c); ++_a)
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define all(x) begin(x),end(x)
#define mask(i) (1LL << (i))
#define bit(x, i) (((x) >> (i)) & 1)
#define bp __builtin_popcountll
#define file "test"

template<class X, class Y>
    bool minz(X &x, const Y &y) {
        if (x > y) {
            x = y;
            return true;
        } return false;
    }
template<class X, class Y>
    bool maxz(X &x, const Y &y) {
        if (x < y) {
            x = y;
            return true;
        } return false;
    }

const int N = 5e5 + 5;
const ll oo = (ll) 1e16;
const ll mod = 1e9 + 7; // 998244353;

ll a[N], b[N], n;

void solve (){
    cin >> n;

    a[0] = oo;
    b[0] = mod;
    stack <int> s;
    s.push(0);

    ll res = 0;

    forr (i, 1, n){
        cin >> a[i] >> b[i];
        ll mx = 0;
        while (a[i] >= a[s.top()] || b[s.top()] == b[i]){
            if (b[i] == b[s.top()]){
                a[i] += a[s.top()] - mx;
            } else {
                mx = max (mx, a[s.top()]);
            }
            s.pop();
        }
        s.push(i);
        res = max (res, max(mx, a[i])); 
        cout << res << " ";
    }
    cout << "\n";
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifdef hqm
        freopen(file".inp", "r", stdin); freopen(file".out", "w", stdout);
    #endif

    int q = 1;
    cin >> q;
    while (q--)
        solve();

    return 0;
}
/*



*/