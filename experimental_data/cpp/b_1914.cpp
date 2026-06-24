#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define PII pair<int,int>
#define ll long long
template<typename... Args>void rd(Args&... args);

#define multicase 1
#define N 500005
#define mod 998244353
// #define mod 1000000007

int a[N], b[N];

void init() { 
    //     M.reserve(1024); M.max_load_factor(0.25);
}

void solve() {
    int n,k; rd(n,k); 
    for(int i=n-k;i<=n;++i) cout<<i<<' ';
    for(int i=n-k-1;i;--i) cout<<i<<' ';
    puts("");
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