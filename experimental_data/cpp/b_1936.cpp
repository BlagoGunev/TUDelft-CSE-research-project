#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define PII pair<int,int>
#define ll long long
template<typename... Args>void rd(Args&... args);

#define multicase 1
#define N 1000005
// #define mod 998244353
#define mod 1000000007

int a[N], b[N];

void init() { 
    //     M.reserve(1024); M.max_load_factor(0.25);
}

char c[N];
vector<ll>R, L;
void solve() {
    int n; rd(n);
    cin>>c+1;
    R.pb(0);
    L.pb(0);
    for(int i=1;i<=n;++i) 
        if(c[i]=='>') R.pb(i);
        else L.pb(i);
    for(int i=1;i<R.size();++i) R[i]+=R[i-1];
    for(int i=1;i<L.size();++i) L[i]+=L[i-1];
    int Lid=0, Rid=0;
    int cRL=L.size()-1, cLR=0;
    for(int i=1;i<=n;++i) {
        if(c[i-1]=='>') cLR++;
        if(c[i]=='<') cRL--;
        if(c[i]=='<') Lid++;
        ll ans;
        // cerr<<":::"<<cLR<<' '<<cRL<<' '<<Lid<<' '<<Rid<<endl;
        if(c[i]=='>') {
            if(cRL <= cLR) ans = n+1 - i + 2*(L[Lid+cRL]-L[Lid]) - 2*(R[Rid]-R[Rid-cRL]); 
            else ans = -i + 0 + 2*(L[Lid+cLR+1]-L[Lid]) - 2*(R[Rid]-R[Rid-cLR]); 
        } else {
            if(cRL < cLR) ans = n+1 + i + 2*(L[Lid+cRL]-L[Lid]) - 2*(R[Rid]-R[Rid-cRL-1]); 
            else ans = i - 0 + 2*(L[Lid+cLR]-L[Lid]) - 2*(R[Rid]-R[Rid-cLR]);//, cerr<<L[Lid+cLR]<<' '<<L[Lid]<<' '<<R[Rid]<<' '<<R[Rid-cLR]<<endl; 
        }
        if(c[i]=='>') Rid++;
        printf("%lld ", ans);
    }
    puts("");
    L.clear();
    R.clear();
}

int main() {
    init();
    #if multicase
    int _; cin>>_; while(_--) solve(); 
    #else
    solve();
    #endif
}

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