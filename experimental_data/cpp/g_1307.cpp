#include <bits/stdc++.h>

using namespace std;

using i64=long long;
using u64=unsigned long long;
using db=double;
using pii=pair<int,int>;
using vi=vector<int>;

template<typename T>
inline T read(){
    T x=0,f=0;char ch=getchar();
    while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();
    while(isdigit(ch)) x=x*10+(ch-'0'),ch=getchar();
    return f?-x:x;
}

#define rdi read<int>
#define rdi64 read<i64>
#define fi first
#define se second
#define pb push_back

const int N=55;
const i64 INFl=4e18;

int n,m,q;
struct Edge{int to,nxt,f,w;}e[N*N*4];
int head[N],tot=1;

void add_e(int x,int y,int f,int w){
    e[++tot]={y,head[x],f,w};head[x]=tot;
    e[++tot]={x,head[y],0,-w};head[y]=tot;
}

i64 dis[N];int pre[N];
bool spfa(int n,int S,int T){
    static int inq[N];
    queue<int> q;
    fill(dis+1,dis+n+1,INFl);
    dis[S]=0,q.push(S),inq[S]=1;
    while(!q.empty()){
        int x=q.front();
        q.pop(),inq[x]=0;
        for(int i=head[x];i;i=e[i].nxt){
            int y=e[i].to;
            if(e[i].f&&dis[y]>dis[x]+e[i].w){
                dis[y]=dis[x]+e[i].w,pre[y]=i;
                if(!inq[y]) inq[y]=1,q.push(y);
            }
        }
    }
    return dis[T]!=INFl;
}

vector<pair<int,i64>> cv;
void calc(int n,int S,int T){
    int sf=0;i64 sc=0;
    while(spfa(n,S,T)){
        int x=T;i64 fl=INFl;
        while(x!=S) fl=min(fl,(i64)e[pre[x]].f),x=e[pre[x]^1].to;
        x=T,sf+=fl,sc+=fl*dis[T];
        while(x!=S) e[pre[x]].f-=fl,e[pre[x]^1].f+=fl,x=e[pre[x]^1].to;
        cv.pb({sf,sc});
    }
}

db query(int x){
    db ret=INFl;
    for(auto cur:cv) ret=min(ret,1.*(cur.se+x)/cur.fi);
    return ret;
}

int main(){
#ifdef LOCAL
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
#endif
    n=rdi(),m=rdi();
    for(int i=1;i<=m;i++){
        int x=rdi(),y=rdi(),w=rdi();
        add_e(x,y,1,w);
    }
    calc(n,1,n);
    q=rdi();
    while(q--){
        int x=rdi();
        cout<<fixed<<setprecision(7)<<query(x)<<'\n';
    }
    return 0;
}