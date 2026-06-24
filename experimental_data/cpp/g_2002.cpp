#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rep1(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < (t); ++i)
#define rng(a) a.begin(),a.end()
#define rrng(a) a.rbegin(),a.rend()
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define em emplace
#define pob pop_back
#define sz(x) (int)(x).size()
#define pcnt __builtin_popcountll
#define snuke srand((unsigned)clock()+(unsigned)time(NULL));
#define newline puts("")
#define vc vector
using namespace std;
template<class T> using vv = vc<vc<T>>;
template<class T> using PQ = priority_queue<T,vc<T>,greater<T>>;
using uint = unsigned; using ull = unsigned long long;
using vi = vc<int>; using vvi = vv<int>; using vvvi = vv<vi>;
using ll = long long; using vl = vc<ll>; using vvl = vv<ll>; using vvvl = vv<vl>;
using P = pair<int,int>; using vp = vc<P>; using vvp = vv<P>; using LP = pair<ll,ll>;
int geti(){int x;scanf("%d",&x);return x;}
vi pm(int n, int s=0) { vi a(n); iota(rng(a),s); return a;}
template<class T1,class T2>istream& operator>>(istream&i,pair<T1,T2>&v){return i>>v.fi>>v.se;}
template<class T1,class T2>ostream& operator<<(ostream&o,const pair<T1,T2>&v){return o<<v.fi<<","<<v.se;}
template<class T>istream& operator>>(istream&i,vc<T>&v){rep(j,sz(v))i>>v[j];return i;}
template<class T>string join(const T&v,const string&d=""){stringstream s;rep(i,sz(v))(i?s<<d:s)<<v[i];return s.str();}
template<class T>ostream& operator<<(ostream&o,const vc<T>&v){if(sz(v))o<<join(v," ");return o;}
template<class T>void vin(vc<T>&a){int n;cin>>n;a=vc<T>(n);cin>>a;}
template<class T>void vin(vv<T>&a){int n,m;cin>>n>>m;a=vv<T>(n,vc<T>(m));cin>>a;}
template<class T1,class T2>void operator--(pair<T1,T2>&a,int){a.fi--;a.se--;}
template<class T1,class T2>void operator++(pair<T1,T2>&a,int){a.fi++;a.se++;}
template<class T>void operator--(vc<T>&a,int){for(T&x:a)x--;}
template<class T>void operator++(vc<T>&a,int){for(T&x:a)x++;}
template<class T>void operator+=(vc<T>&a,T b){for(T&x:a)x+=b;}
template<class T>void operator-=(vc<T>&a,T b){for(T&x:a)x-=b;}
template<class T>void operator*=(vc<T>&a,T b){for(T&x:a)x*=b;}
template<class T>void operator/=(vc<T>&a,T b){for(T&x:a)x/=b;}
template<class T>void operator+=(vc<T>&a,const vc<T>&b){a.insert(a.end(),rng(b));}
template<class T1,class T2>pair<T1,T2>operator+(const pair<T1,T2>&a,const pair<T1,T2>&b){return {a.fi+b.fi,a.se+b.se};}
template<class T1,class T2>pair<T1,T2>operator-(const pair<T1,T2>&a,const pair<T1,T2>&b){return {a.fi-b.fi,a.se-b.se};}
template<class T>pair<T,T>operator*(const pair<T,T>&a,T b){return {a.fi*b,a.se*b};}
template<class T1,class T2>bool mins(T1& x,const T2&y){if(y<x){x=y;return true;}else return false;}
template<class T1,class T2>bool maxs(T1& x,const T2&y){if(x<y){x=y;return true;}else return false;}
template<class T>T min(const vc<T>&a){return *min_element(rng(a));}
template<class T>T max(const vc<T>&a){return *max_element(rng(a));}
template<class Tx,class Ty>Tx dup(Tx x, Ty y){return (x+y-1)/y;}
template<class T>ll suma(const vc<T>&a){ll s=0;for(auto&&x:a)s+=x;return s;}
template<class T>ll suma(const vv<T>&a){ll s=0;for(auto&&x:a)s+=suma(x);return s;}
template<class T>void uni(T&a){sort(rng(a));a.erase(unique(rng(a)),a.end());}
template<class T>void prepend(vc<T>&a,const T&x){a.insert(a.begin(),x);}
const double eps = 1e-10;
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
#define dame { puts("-1"); return;}
#define yes { puts("Yes"); return;}
#define no { puts("No"); return;}
#define rtn(x) { cout<<(x)<<'\n'; return;} // flush!
#define yn {puts("Yes");}else{puts("No");}
template<class F> ll bis(ll ac, ll wa, F f) {
  while (abs(ac-wa)>1) { ll wj=(ac+wa)/2; (f(wj)?ac:wa)=wj;} return ac;
}
template<class F> ll bis2(F f) { // 0:true -> max true
  ll r = 1; while (f(r)) r <<= 1; return bis(r>>1,r,f);
}
template<typename T> int lwb(const vector<T>& a, const T& x) { return lower_bound(rng(a), x) - a.begin();}
template<typename T> int upb(const vector<T>& a, const T& x) { return upper_bound(rng(a), x) - a.begin();}
template<typename T> bool exists(const vector<T>& a, const T& x) { return binary_search(rng(a), x);}

// ull -> Val (maspy orz)
template <typename Val>
struct HashMap {
  HashMap(uint n = 0) { build(n);}
  void build(uint n) {
    uint k = 8; while (k < n*2) k *= 2;
    cap = k/2; mask = k-1; key.resize(k); val.resize(k); used.assign(k,0);
  }
  void clear() { used.assign(sz(used),0);} // keep size
  int size() { return sz(used)/2 - cap;}
  int index(const ull& k) {
    int i = hash(k); while (used[i] && key[i] != k) i = (i+1)&mask;
    return i;
  }
  Val& operator[](const ull& k) {
    if (cap == 0) extend();
    int i = index(k);
    if (!used[i]) used[i] = 1, key[i] = k, val[i] = Val{}, --cap;
    return val[i];
  }
  bool count(const ull& k) { return used[index(k)];}
  template <class F> void each(F f) { rep(i,sz(used)) if (used[i]) f(key[i],val[i]);}
private:
  uint cap, mask; vc<ull> key; vc<Val> val; vc<bool> used;
  ull hash(ull x) {
    static const ull FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
    x += FIXED_RANDOM;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return (x ^ (x >> 31)) & mask;
  }
  void extend() {
    vc<pair<ull,Val>> dat; dat.reserve(size());
    rep(i,sz(used)) if (used[i]) dat.eb(key[i],val[i]);
    build(2*sz(dat)); for (auto& [a,b] : dat) (*this)[a] = b;
  }
};

struct Solver {
  void solve() {
    int n;
    cin>>n;
    vvl a(n-1,vl(n));
    vvl b(n,vl(n-1));
    cin>>a>>b;
    rep(i,n-1)rep(j,n) a[i][j] = 1ll<<a[i][j];
    rep(i,n)rep(j,n-1) b[i][j] = 1ll<<b[i][j];

    int ln = (n+n-2)*2/3, rn = n+n-2-ln;

    vc<HashMap<char>> sr(rn+1);
    rep(i,rn+1) sr[i][0] = 0;
    {
      auto f = [&](auto f, int i, int j, ll x) -> void {
        if (i+j == rn) {
          for (ll nx = x; nx; nx = (nx-1)&x) sr[i][nx] = 0;
          return;
        }
        f(f,i+1,j,x|a[i][j]);
        f(f,i,j+1,x|b[i][j]);
      };
      f(f,0,0,0);
    }

    int ans = 0;
    vl xs(40);
    rep(i,40) xs[i] = (1ll<<i)-1;
    {
      auto f = [&](auto f, int i, int j, ll x) -> void {
        if (i+j == rn) {
          while (1) {
            if (!sr[i].count((x&xs[ans+1])^xs[ans+1])) break;
            ans++;
          }
          return;
        }
        if (i) f(f,i-1,j,x|a[i-1][j]);
        if (j) f(f,i,j-1,x|b[i][j-1]);
      };
      f(f,n-1,n-1,0);
    }

    printf("%d\n",ans);
  }
};

int main() {
  // cin.tie(nullptr); ios::sync_with_stdio(false);
  int ts = 1;
  scanf("%d",&ts);
  rep1(ti,ts) {
    Solver solver;
    solver.solve();
  }
  return 0;
}