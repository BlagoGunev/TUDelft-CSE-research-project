#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define PII pair<int,int>
#define ll long long
#define multicase 1
#define N 500005
#define mod 998244353

int a[N], b[N], ok[N];

void read(int&x) {
    x=0; char ch=getchar(); int f=1;
    while(!isdigit(ch)) f=ch=='-'?-1:1, ch=getchar();
    while(isdigit(ch)) x=x*10+ch-48, ch=getchar();
    x=f*x;
}

void read(ll&x) {
    x=0; char ch=getchar(); int f=1;
    while(!isdigit(ch)) f=ch=='-'?-1:1, ch=getchar();
    while(isdigit(ch)) x=x*10+ch-48, ch=getchar();
    x=f*x;
}

template<typename... Args>
void rd(Args&... args) {
    std::initializer_list<int>{(read(args), 0)...};
}


void init() { 
//     M.reserve(1024); M.max_load_factor(0.25);
}

set<int>small, big;
vector<int>v[N], w[N];
void solve() {
    int n; rd(n); 
    small.clear(); big.clear();
    small.insert(0); small.insert(n+1);
    big.insert(0); big.insert(n+1);
    for(int i=1;i<=n;++i) v[i].clear(), w[i].clear(), big.insert(i);
    for(int i=1;i<=n;++i) rd(a[i]), v[a[i]].pb(i);
    for(int i=1;i<=n;++i) rd(b[i]), w[b[i]].pb(i);
    for(int i=1;i<=n;++i) {
        for(int x:v[i]) big.erase(x);
        for(int x:w[i]) {
            // cerr<<x<<endl;
            bool f=0;
            auto p=upper_bound(v[i].begin(),v[i].end(),x);
            int y;
            if(p!=v[i].begin()) {
                y=*--p;
                // cerr<<'l'<<y<<' '<<*big.lower_bound(y)<<endl;
                if(*big.lower_bound(y)>x && *small.lower_bound(y)>x) f=1;
            }
            p=lower_bound(v[i].begin(),v[i].end(),x);
            if(p!=v[i].end()) {
                y=*p;
                // cerr<<'r'<<y<<endl;
                if(*big.lower_bound(x)>y && *small.lower_bound(x)>y) f=1;
            }
            if(!f) {puts("NO"); return;}
        }
        for(int x:w[i]) small.insert(x);
    }
    puts("YES");
}

int main() {
    init();
    #if multicase
    int _; cin>>_; while(_--) solve(); 
    #else
    solve();
    #endif
}

// Fenwick tree
int t[N];
void add(int x,int v){for(;x<N;x+=x&-x)t[x]+=v;}
int ask(int x,int a=0){for(;x;x^=x&-x)a+=t[x]; return a;}

// Math
int gcd(int a,int b){return b?gcd(b,a%b):a;}
ll qp(ll b,int t,ll a=1){for(;t;t>>=1,b=b*b%mod)if(t&1)a=a*b%mod; return a;}
int inv(ll x){return qp(x,mod-2);}

// Joint Set
int f[N];
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}