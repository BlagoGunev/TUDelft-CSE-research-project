#ifdef t9unkubj
#include"template.h"
//#include"template_no_debug.h"
#else
#undef _GLIBCXX_DEBUG
#pragma GCC optimize("O3")
#define dbg(...) 199958
using namespace std;
#include<bits/stdc++.h>
using uint=unsigned;
using ll=long long;
using ull=unsigned long long;
using ld=long double;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
template<class T>using vc=vector<T>;
template<class T>using vvc=vc<vc<T>>;
template<class T>using vvvc=vvc<vc<T>>;
using vi=vc<int>;
using vvi=vc<vi>;
using vvvi=vc<vvi>;
using vl=vc<ll>;
using vvl=vc<vl>;
using vvvl=vc<vvl>;
template<class T>using smpq=priority_queue<T,vector<T>,greater<T>>;
template<class T>using bipq=priority_queue<T>;
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define REP(i,j,n) for(ll i=(j);i<(ll)(n);i++)
#define DREP(i,n,m) for(ll i=(n);i>=(m);i--)
#define drep(i,n) for(ll i=((n)-1);i>=0;i--)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define is insert
#define bg begin()
#define ed end()
void scan(int&a) { cin >> a; }
void scan(ll&a) { cin >> a; }
void scan(string&a) { cin >> a; }
void scan(char&a) { cin >> a; }
void scan(uint&a) { cin >> a; }
void scan(ull&a) { cin >> a; }
void scan(bool&a) { cin >> a; }
void scan(ld&a){ cin>> a;}
template<class T> void scan(vector<T>&a) { for(auto&x:a) scan(x); }
void read() {}
template<class Head, class... Tail> void read(Head&head, Tail&... tail) { scan(head); read(tail...); }
#define INT(...) int __VA_ARGS__; read(__VA_ARGS__);
#define LL(...) ll __VA_ARGS__; read(__VA_ARGS__);
#define ULL(...) ull __VA_ARGS__; read(__VA_ARGS__);
#define STR(...) string __VA_ARGS__; read(__VA_ARGS__);
#define CHR(...) char __VA_ARGS__; read(__VA_ARGS__);
#define DBL(...) double __VA_ARGS__; read(__VA_ARGS__);
#define LD(...) ld __VA_ARGS__; read(__VA_ARGS__);
#define VC(type, name, ...) vector<type> name(__VA_ARGS__); read(name);
#define VVC(type, name, size, ...) vector<vector<type>> name(size, vector<type>(__VA_ARGS__)); read(name);
void print(int a) { cout << a; }
void print(ll a) { cout << a; }
void print(string a) { cout << a; }
void print(char a) { cout << a; }
void print(uint a) { cout << a; }
void print(bool a) { cout << a; }
void print(ull a) { cout << a; }
void print(double a) { cout << a; }
void print(ld a){ cout<< a; }
template<class T> void print(vector<T>a) { for(int i=0;i<(int)a.size();i++){if(i)cout<<" ";print(a[i]);}cout<<endl;}
void PRT() { cout <<endl; return ; }
template<class T> void PRT(T a) { print(a); cout <<endl; return; }
template<class Head, class... Tail> void PRT(Head head, Tail ... tail) { print(head); cout << " "; PRT(tail...); return; }
template<class T,class F>
bool chmin(T &x, F y){
    if(x>y){
        x=y;
        return true;
    }
    return false;
}
template<class T, class F>
bool chmax(T &x, F y){
    if(x<y){
        x=y;
        return true;
    }
    return false;
}
void YesNo(bool b){
    cout<<(b?"Yes":"No")<<endl;
}
void Yes(){
    cout<<"Yes"<<endl;
}
void No(){
    cout<<"No"<<endl;
}
template<class T>
int popcount(T n){
    return __builtin_popcountll(n);
}
template<class T>
T sum(vc<T>&a){
    return accumulate(all(a),T(0));
}
template<class T>
T max(vc<T>&a){
    return *max_element(all(a));
}
template<class T>
T min(vc<T>&a){
    return *min_element(all(a));
}
template<class T>
void unique(vc<T>&a){
    a.erase(unique(all(a)),a.end());
}
vvi readgraph(int n,int m,int off = -1){
    vvi g(n);
    rep(i, m){
        int u,v;
        cin>>u>>v;
        u+=off,v+=off;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    return g;
}
vvi readtree(int n,int off=-1){
    return readgraph(n,n-1,off);
}
template<class T>
vc<T> presum(vc<T> &a){
    vc<T> ret(a.size()+1);
    rep(i,a.size())ret[i+1]=ret[i]+a[i];
    return ret;
}
template<class T, class F>
vc<T> &operator+=(vc<T> &a,F b){
    for (auto&v:a)v += b;
    return a;
}
template<class T, class F>
vc<T> &operator-=(vc<T>&a,F b){
    for (auto&v:a)v-=b;
    return a;
}
template<class T, class F>
vc<T> &operator*=(vc<T>&a,F b){
    for (auto&v:a)v*=b;
    return a;
}
#endif
double pass_time=0;
int a[int(2e5)];
int cnt[int(2e6)];
void solve(){
    INT(n,q);
    rep(i,n)cin>>a[i],a[i]--;
    constexpr int B=300;
    vc<array<int,3>>qs(q);
    rep(i,q){
        INT(l,r);
        --l,--r;
        qs[i]={l,r,int(i)};
    }
    sort(all(qs),[&](auto a,auto b){
        if(a[0]/B!=b[0]/B)return a[0]/B<b[0]/B;
        return a[1]<b[1];
    });
    vi ans(q);
    int r=random_device{}();
    int odd=0;
    auto add=[&](int x){
        cnt[x]++;
        if(cnt[x]%2)++odd;
        else --odd;
    };
    auto erase=[&](int x){
        add(x);
    };
    int nl=0,nr=-1;
    for(auto [l,r,i]:qs){
        while(nl<l)erase(a[nl++]);
        while(nl>l)add(a[--nl]);
        while(nr<r)add(a[++nr]);
        while(nr>r)erase(a[nr--]);
        ans[i]=odd==0;
    }
    for(auto x:ans)YesNo(x);
    for(auto x:a)cnt[x]=0;
}
signed main(){
    #ifdef t9unkubj
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    cin.tie(0)->sync_with_stdio(0);
    pass_time=clock();
    int t=1;
    cin>>t;
    while(t--)solve();
    pass_time=clock()-pass_time;
    dbg(pass_time/CLOCKS_PER_SEC);
}