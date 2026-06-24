#include <cassert>
#include <bitset>
#include <algorithm>
#include <functional>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define sz(a) static_cast<int>(a.size())
#define all(a) a.begin(), a.end()
#define rep(i, a, b) for(int i=int(a); i<=int(b); ++i)
#define irep(i, a, b) for(int i=int(a); i>=int(b); --i)
#define repn(i, n) rep(i, 0, (n)-1)
#define irepn(i, n) irep(i, (n)-1, 0)
#define fillchar(a, x) memset(a, x, sizeof(a))
#define fi first
#define se second
#define pb push_back
#define mp make_pair
typedef long long LL;
typedef pair<LL,LL> PLL;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;
typedef vector<LL> VL;
typedef vector<int> VI;
typedef vector<PII> VPI;
typedef vector<string> VS;
template<class T> bool setmax(T &_a, T _b) { if(_b>_a) { _a=_b; return true; } return false; }
template<class T> bool setmin(T &_a, T _b) { if(_b<_a) { _a=_b; return true; } return false; }
template<class T> T gcd(T _a, T _b) { return _b==0?_a:gcd(_b,_a%_b); }

const int N=2010;

struct Formula {
    bitset<N> g[N]; int r[N];
    int n, m;
    int op(int x) const { return x<=n ? x+n : x-n; }

    void read(int _n, int _m) {
        n=_n; m=_m;
        rep(i, 1, n*2) g[i].reset();
        rep(i, 1, m) {
            int a, b; scanf("%d%d", &a,&b);
            if(a<0) a=-a+n;
            if(b<0) b=-b+n;
            g[op(a)][b]=1;
            g[op(b)][a]=1;
        }
    }

    void go() {
        rep(k, 1, n*2) rep(i, 1, n*2) if(g[i][k]) {
            g[i]|=g[k];
        }

        if(ok()) {
            fillchar(r, 0xff);
            rep(x, 1, n*2) if(g[op(x)][x]) color(x);
        }
    }

    void color(int x) {
        if(r[x]>=0) { assert(r[x]==1); return; }
        r[x]=1, r[op(x)]=0;
        rep(y, 1, n*2) if(g[x][y]) color(y);
    }

    bool ok() {
        rep(x, 1, n) if(g[x][x+n] && g[x+n][x]) return false;
        return true;
    }

    void solve(int c1=-1, int c2=-1) {
        if(c1>0) color(c1);
        if(c2>0) color(c2);
        rep(i, 1, n*2) if(r[i]<0) color(i);
        rep(i, 1, n) printf("%d ", r[i]); printf("\n");
        exit(0);
    }
};

Formula f, g;

int main() {
    int n, m1, m2; scanf("%d%d%d", &n,&m1,&m2);
    f.read(n, m1); f.go();
    g.read(n, m2); g.go();
    bool of=f.ok(), og=g.ok();
    if(of && !og) f.solve();
    else if(!of && og) g.solve();
    else if(of && og) {
        rep(i, 1, n*2) {
            if(f.r[i]==0 && g.r[i]!=0) g.solve(i);
            if(g.r[i]==0 && f.r[i]!=0) f.solve(i);
        }
        rep(i, 1, n*2) rep(j, 1, n*2) if(i!=j && f.r[i]<0 && f.r[j]<0) {
            if(f.g[i][j]!=g.g[i][j]) {
                if(f.g[i][j]) g.solve(i, g.op(j));
                if(g.g[i][j]) f.solve(i, f.op(j));
            }
        }
    }
    printf("SIMILAR\n");

    return 0;
}