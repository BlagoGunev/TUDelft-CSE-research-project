#include <bits/stdc++.h>

using namespace std;

#define rep(i,a,n) for (int i=(a);i<(n);i++)
#define per(i,a,n) for (int i=(n)-1;i>=(a);i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) (int)x.size()

typedef long long ll;
typedef double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<ll,ll>pll;
typedef vector<pii> vpii;

template<typename T>
T getint() {
    T x=0,p=1;
    char ch;
    do{ch=getchar();}while(ch <= ' ');
    if(ch=='-')p=-1,ch=getchar();
    while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
    return x*p;
}

template<typename T1,typename T2>bool umin(T1 &x,const T2&y){if(x>y)return x=y,true;return false;}
template<typename T1,typename T2>bool umax(T1 &x,const T2&y){if(x<y)return x=y,true;return false;}

const int maxn=(int)1e3+10;
const int inf=(int)1e9+5;
const int mod=(int)1e9+7;
const ll llinf=(ll)1e18+5;
const ld pi=acos(-1.0);

int mx[maxn];
vi g[maxn];
vi z;
int we[maxn],b[maxn];
int u[maxn];

void dfs(int v){
    u[v]=1;
    z.pb(v);
    for(int x:g[v]){
        if(u[x]==0)dfs(x);
    }
}

int main(){
    //freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);

    int n=getint<int>();
    int m=getint<int>();
    int w=getint<int>();
    rep(i,0,n){
        we[i]=getint<int>();
    }
    rep(i,0,n)b[i]=getint<int>();
    rep(i,0,m){
        int x=getint<int>()-1;
        int y=getint<int>()-1;
        g[x].pb(y),g[y].pb(x);
    }

    mx[0]=0;
    rep(i,1,w+1)mx[i]=-inf;
    rep(i,0,n){
        if(u[i])continue;
        z.clear();
        dfs(i);

        int W=0,B=0;
        vi best(w+1,-inf);
        best[0]=0;
        for(int x:z){

            per(j,0,w+1){
                if(j-we[x]>=0)umax(best[j],mx[j-we[x]]+b[x]);
            }
            W+=we[x],B+=b[x];
        }
        per(j,0,w+1){
            if(j-W>=0)umax(best[j],mx[j-W]+B);
        }
        rep(i,0,w+1)umax(mx[i],best[i]);
    }
    int res=0;
    rep(i,0,w+1)umax(res,mx[i]);
    printf("%d\n",res);
    return 0;
}