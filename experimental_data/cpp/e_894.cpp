#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
#include <utility>
#define pii pair<int,int>
#define F first
#define S second
#define mkp make_pair
using namespace std;
vector<int> G1[1000005],G2[1000005],tmp;
bool vis[1000005];
void dfs1(int x){
    vis[x]=1;
    for(int y:G1[x]) if(!vis[y]) dfs1(y);
    tmp.push_back(x);
}
int cur=0,id[1000005];
void dfs2(int x){
    id[x]=cur;
    for(int y:G2[x]) if(!id[y]) dfs2(y);
}
int a[1000005],b[1000005];
long long w[1000005],v[1000005],d[1000005];
vector<pii> G[1000005];
long long dp(int x){
    if(d[x]>=0) return d[x];
    long long ma=0;
    for(pii p:G[x]) ma=max(ma,w[p.S]+dp(p.F));
    return d[x]=v[x]+ma;
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        scanf("%d%d%lld",&a[i],&b[i],&w[i]);
        G1[a[i]].push_back(b[i]);
        G2[b[i]].push_back(a[i]);
    }
    for(int i=1;i<=n;i++) if(!vis[i]){
        dfs1(i);
    }
    for(int i=n-1;i>=0;i--) if(!id[tmp[i]]){
        cur++;
        dfs2(tmp[i]);
    }
    for(int i=0;i<m;i++){
        if(id[a[i]]!=id[b[i]]) G[id[a[i]]].push_back(mkp(id[b[i]],i));
        else{
            long long XD=(long long)sqrt(w[i]*2)+5;
            while((XD+1)*XD>w[i]*2) XD--;
            v[id[a[i]]]+=(w[i]*(XD+1)-XD*(XD+1)*(XD+2)/6);
        }
    }
    int s;
    scanf("%d",&s);
    for(int i=1;i<=cur;i++) d[i]=-1;
    printf("%lld\n",dp(id[s]));
    return 0;
}