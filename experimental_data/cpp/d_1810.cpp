#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <set>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair <int,int> Pii;
#define reg register
#define mp make_pair
#define pb push_back
#define Mod1(x) ((x>=P)&&(x-=P))
#define Mod2(x) ((x<0)&&(x+=P))
#define rep(i,a,b) for(int i=a,i##end=b;i<=i##end;++i)
#define drep(i,a,b) for(int i=a,i##end=b;i>=i##end;--i)
template <class T> inline void cmin(T &a,T b){ ((a>b)&&(a=b)); }
template <class T> inline void cmax(T &a,T b){ ((a<b)&&(a=b)); }

// char buf[200000], *p1, *p2;
// #define getchar() (((p1==p2) && (p2 = (p1 = buf) + fread(buf, 1, 200000, stdin))), *p1++)

char IO;
template <class T=int> T rd(){
	T s=0; int f=0;
	while(!isdigit(IO=getchar())) f|=IO=='-';
	do s=(s<<1)+(s<<3)+(IO^'0');
	while(isdigit(IO=getchar()));
	return f?-s:s;
}

bool Mbe;
const int N = 1e5 + 10, INF = 1e9 + 10, P = 1e9 + 7;

int n, m;


ll calc(ll h, int a, int b) {
    if(!h) return 0;
    if(h <= a) return 1;
    return (h - a + a - b - 1) / (a - b) + 1;
}

int main() {
    rep(_,1,rd()) {
        ll l = 1, r = 1e18;
        rep(t, 1, rd()) {
            int op = rd();
            if(op == 1) {
                int a = rd(), b = rd(), n = rd();
                ll tl = max(1ll * (n - 1) * (a - b) + 1,
                            n == 1 ? 1 : (1ll * (n - 2) * (a - b) + a + 1));
                ll tr = 1ll * (n - 1) * (a - b) + a;
                if(tl > r || tr < l) printf("0 ");
                else cmin(r, tr), cmax(l, tl), printf("1 ");
                // cout << "$(" << l << ',' << r << ")$ "<< endl;
            } else {
                int a = rd(), b = rd();
                ll w1 = calc(l, a, b), w2 = calc(r, a, b);
                // cout << "#(" << w1 << ',' << w2 << ")# "<< endl;
                if(w1 != w2) printf("-1 ");
                else printf("%lld ", w1);
            }
        }
        puts("");
    }
}