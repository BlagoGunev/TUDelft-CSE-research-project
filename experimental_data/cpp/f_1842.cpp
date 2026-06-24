#include <bits/stdc++.h>
#define F(i,x,y) for(int i=(x);i<=(y);i++)
#define DF(i,x,y) for(int i=(x);i>=(y);i--)
#define ms(x,y) memset(x,y,sizeof(x))
#define SZ(x) (int)x.size()-1
#define all(x) x.begin(),x.end()
#define pb push_back
using namespace std;
typedef long long LL;
typedef unsigned long long ull;
typedef pair<int,int> pii;
template<typename T> void chkmax(T &x,T y){ x=max(x,y);}
template<typename T> void chkmin(T &x,T y){ x=min(x,y);}
template<typename T> void read(T &FF){
    FF=0;int RR=1;char ch=getchar();
    for(;!isdigit(ch);ch=getchar()) if(ch=='-') RR=-1;
    for(;isdigit(ch);ch=getchar()) FF=(FF<<1)+(FF<<3)+ch-48;
    FF*=RR;
}
const int N=5010;
int n,dep[N];
vector<int> G[N];
LL ans[N];
void dfs(int u,int fa){
    for(int v:G[u]) if(v!=fa) dep[v]=dep[u]+1,dfs(v,u);
}
int main(){
    read(n);
    F(i,1,n-1){
        int x,y;read(x),read(y);
        G[x].pb(y),G[y].pb(x);
    }
    F(rt,1,n){
        dep[rt]=0,dfs(rt,0);
        sort(dep+1,dep+n+1);
        LL val=0;
        F(i,0,n) val-=2*dep[i],chkmax(ans[i],val+1ll*i*(n-1));
    }
    F(i,0,n) printf("%lld ",ans[i]);puts("");
    return 0;
}