#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define DEBUG
#ifdef DEBUG
template <class T, class U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
    os << '(' << p.first << ',' << p.second << ')';
    return os;
}
template <class T> ostream &operator<<(ostream &os, const vector<T> &v) {
    os << '{';
    for(int i = 0; i < (int)v.size(); i++) {
        if(i) { os << ','; }
        os << v[i];
    }
    os << '}';
    return os;
}
ostream &operator<<(ostream &os, const set<int> &se){
    os << '{';
    int now = 0;
    for(auto x : se){
        if(now) { os << ','; }
        os << x; 
        now++;
    }
    os << '}';
    return os;
}
void debugg() { cerr << endl; }
template <class T, class... Args>
void debugg(const T &x, const Args &... args) {
    cerr << " " << x;
    debugg(args...);
}
#define debug(...)                                                             \
    cerr << __LINE__ << " [" << #__VA_ARGS__ << "]: ", debugg(__VA_ARGS__)
#define dump(x) cerr << __LINE__ << " " << #x << " = " << (x) << endl
#else
#define debug(...) (void(0))
#define dump(x) (void(0))
#endif
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<double> vd;
typedef pair<ll,ll> P;
typedef pair<int,int> pii;
typedef vector<P> vpl;
typedef tuple<ll,ll,ll> tapu;
#define rep(i,n) for(int i=0; i<(n); i++)
#define REP(i,a,b) for(int i=(a); i<(b); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
const int inf = (1<<30)-1;
const ll linf = 1LL<<61;
const int MAX = 510000;
int dy[8] = {0,1,0,-1,1,-1,-1,1};
int dx[8] = {-1,0,1,0,1,-1,1,-1};
const double pi = acos(-1);
const double eps = 1e-8;
template<typename T1,typename T2> inline bool chmin(T1 &a,T2 b){
	if(a>=b){
		a = b; return true;
	}
	else return false;
}
template<typename T1,typename T2> inline bool chmax(T1 &a,T2 b){
	if(a<b){
		a = b; return true;
	}
	else return false;
}
template<typename T> inline void print(T &a){
    int sz = a.size();
    for(auto itr = a.begin(); itr != a.end(); itr++){
		cout << *itr;
        sz--;
        if(sz) cout << " ";
	}
    cout << "\n";
}
template<typename T1,typename T2> inline void print2(T1 a, T2 b){
	cout << a << " " << b << "\n";
}
template<typename T1,typename T2,typename T3> inline void print3(T1 a, T2 b, T3 c){
	cout << a << " " << b << " " << c << "\n";
}
void mark() {cout << "#" << "\n";}
ll pcount(ll x) {return __builtin_popcountll(x);}
// #include <atcoder/lazysegtree>
// using namespace atcoder;
const int mod = 1e9 + 7;
//const int mod = 998244353;

ll c[101010];
ll p[101010];
ll sc[101010];

void solve(){
    int n; cin >> n;
    vl a(n); rep(i,n) cin >> a[i];
    rep(i,n) c[a[i]]++;
    REP(i,1,100001) sc[i] = sc[i-1] + c[i];

    ll ans = 0;
    for(int i=100000; i>=1; i--){
        ll res = 0;
        ll s = 0;
        for(int j=i; j<=100000; j+=i){
            res -= p[j];
            if(c[j] >= 3) res += c[j] * (c[j]-1) * (c[j]-2) / 6;
            if(c[j] >= 2){
                res += c[j] * (c[j]-1) / 2 * (sc[100000] - sc[j]);
                res += c[j] * (c[j]-1) / 2 * s;
            }
            res += c[j] * s * (sc[100000] - sc[j]);
            s += c[j];
        }
        ans += res * i;
        p[i] = res;
    }

    cout << ans << "\n";

    rep(i,101010){
        c[i] = p[i] = sc[i] = 0;
    }
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}