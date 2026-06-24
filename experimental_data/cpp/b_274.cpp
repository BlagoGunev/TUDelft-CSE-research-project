#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <string.h>
#include <ctime>
#include <limits.h>
using namespace std;

typedef long long ll;
const double pi=acos(-1.0);
const double eps=1e-11;
//const ll INF=(_I64_MAX)/2;
//#pragma comment(linker, "/STACK:102400000,102400000")
const int inf=0x3f3f3f3f;
#define maxx(a) memset(a, 0x3f, sizeof(a))
#define zero(a) memset(a, 0, sizeof(a))
template<class T>void show(T a, int n){for(int i=0; i<n; ++i) cout<<a[i]<<' '; cout<<endl;}
template<class T>void show(T a, int r, int l){for(int i=0; i<r; ++i)show(a[i],l);cout<<endl;}
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
#define srep(i,n) for(i = 1;i <= n;i ++)
#define M ((l+r)>>1)
#define lc (o<<1)
#define rc (lc|1)
#define MP make_pair
typedef pair<int,int> PII;

int n,m;
const int N=100005;
struct edge{
    int next,v;
}e[N*2];
int head[N],tot;
bool f[N];
void init(){
    zero(head);
    tot=1;
    zero(f);
}
inline void add(int u,int v){
    e[tot].v=v;
    e[tot].next=head[u];
    head[u]=tot++;
}
int value[N];
struct sy{
    ll aa,bb;
    sy(ll a =0,ll b = 0):aa(a),bb(b){}
};
sy doit(int x){
    ll a = 0,b = 0;
    f[x] = 1;
    int i,j;
    for(i = head[x];i;i = e[i].next){
        int t = e[i].v;
        if(!f[t]){
            sy tp = doit(t);
            a = max(a,tp.aa);
            b = max(b,tp.bb);
        }
    }
    ll c = a - b + value[x];
    if(c > 0) return sy(a,b+c);
    else return sy(a-c,b);
}
int main()
{
#ifndef ONLINE_JUDGE
   freopen("in.txt","r",stdin); 
  // freopen("out.txt","w",stdout);
#endif
    init();
    scanf("%d",&n);
    int i,j,a,b;
    rep(i,n-1){
        scanf("%d%d",&a,&b);
        add(a,b);
        add(b,a);
    }
    srep(i,n) scanf("%d",value+i);

    sy ans = doit(1);
    cout<<ans.aa + ans.bb;
#ifndef ONLINE_JUDGE
    cerr << "time = " << clock() << " ms" << endl;
#endif

return 0;
}