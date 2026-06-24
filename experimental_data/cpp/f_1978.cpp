//#pragma GCC optimize(2)
#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math,no-stack-protector")
//#pragma GCC target("sse,sse2,avx,avx2,bmi,bmi2,lzcnt,popcnt,avx512vl,avx512f,tune=native")
//#include"testlib.h"
#include<bits/stdc++.h>
#define int long long
//define ll long long
#define _i __int128
#define endl '\n'
typedef std::pair<int,int> pii;
const long long INF=1000000000000000000;
namespace BaSiC{
void IOS(){std::ios::sync_with_stdio(false);std::cin.tie(nullptr);}
void to_min(int& x,int y){if(x>y) x=y;}
void to_max(int& x,int y){if(x<y) x=y;}
void YES(){std::cout<<"YES"<<endl;}
void Yes(){std::cout<<"Yes"<<endl;}
void yes(){std::cout<<"yes"<<endl;}
void TAK(){std::cout<<"TAK"<<endl;}
void Takahashi(){std::cout<<"Takahashi"<<endl;}
void NO(){std::cout<<"NO"<<endl;}
void No(){std::cout<<"No"<<endl;}
void no(){std::cout<<"no"<<endl;}
void NIE(){std::cout<<"NIE"<<endl;}
void Aoki(){std::cout<<"Aoki"<<endl;}
void YN(bool cond){if(cond) YES();else NO();}
void Yn(bool cond){if(cond) Yes();else No();}
void yn(bool cond){if(cond) yes();else no();}
void NT(bool cond){if(cond) TAK();else NIE();}
void atc(bool cond){if(cond) Takahashi();else Aoki();}
}
using namespace BaSiC;
//------------------[template:basic]------------------//
void read(__int128 &x){
	// read a __int128 variable
	char c;bool f=0;
	while(((c=getchar())<'0'||c>'9')&&c!='-');
	if(c=='-'){f=1;c=getchar();}x=c-'0';
	while((c=getchar())>='0'&&c<='9') x=x*10+c-'0';
	if(f) x=-x;
}
void write(__int128 x){
	// print a __int128 variable
	if(x<0){putchar('-');x=-x;}
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
//------------------[template:128io]------------------//
struct BIT{
    int sz;
    std::vector<int> C;
    BIT(int _sz){sz=_sz;C.resize(sz+1);}
    int lowbit(int x){return x&-x;}
    void update(int x,int d){if(x) while(x<=sz) C[x]+=d,x+=lowbit(x);}
    void update(int l,int r,int d){update(l,d);update(r+1,-d);}
    int query(int x){int res=0;while(x) res+=C[x],x-=lowbit(x);return res;}
    int query(int l,int r){return query(r)-(l?query(l-1):0);}
    void print(){for(int i=1;i<=sz;i++) std::cout<<C[i]<<" ";std::cout<<endl;}
};
//-------------------[template:BIT]-------------------//
struct Dij_Node{
    int id,w;
    bool operator<(const Dij_Node& x)const{
        return w==x.w?id<x.id:w>x.w;
    }
};
struct Dij{
    int n,s;
    std::vector<std::vector<Dij_Node> > b;
    std::vector<int> dis;
    std::vector<int> vis;
    std::priority_queue<Dij_Node> pq;
    Dij(int sz,int _s){
        n=sz;s=_s;
        b.resize(sz+1);dis.resize(sz+1);vis.resize(sz+1);
    }
    void add(int u,int v,int w){b[u].push_back({v,w});}
    void op(){
        for(int i=1;i<=n;i++) dis[i]=INF;
        dis[s]=0;pq.push({s,0});
        while(!pq.empty()){
            auto t=pq.top();pq.pop();
            int u=t.id;
            if(vis[u]) continue;
            vis[u]=1;
            for(auto i:b[u]){
                int v=i.id;
                if(vis[v]) continue;
                if(dis[v]>dis[u]+i.w) dis[v]=dis[u]+i.w,pq.push({v,dis[v]});
            }
        }
    }
};
//-------------------[template:Dij]-------------------//
struct Dinic_Edge{
    int to,mp,w;
};
struct Dinic{
    int n,m,s,t;
    std::vector<int> dis,cur;
    std::vector<std::vector<Dinic_Edge> > b;
    Dinic(int _n,int _m,int _s,int _t):n(_n),m(_m),s(_s),t(_t){
        dis.resize(_n+1);cur.resize(_n+1);
        b.resize(_n+1);
    }
    inline void Add(int u,int v,int w){
        b[u].push_back({v,(int)b[v].size(),w});
        b[v].push_back({u,(int)b[u].size()-1,0});
    }
    inline bool bfs(){
        std::queue<int> q;q.push(s);
        for(int i=1;i<=n;i++) dis[i]=cur[i]=0;dis[s]=1;
        while(!q.empty()){
            int u=q.front();q.pop();
            for(auto i:b[u]){
                int v=i.to;
                if(dis[v]||!i.w) continue;
                q.push(v);dis[v]=dis[u]+1;
            }
        }
        return dis[t];
    }
    int dfs(int u,int flow){
        if(u==t) return flow;
        int res=0;
        for(int i=cur[u];i<b[u].size();i++){
            int v=b[u][i].to;cur[u]=i;
            if(dis[v]!=dis[u]+1||!b[u][i].w) continue;
            int curflow=dfs(v,std::min(flow-res,b[u][i].w));
            res+=curflow;b[u][i].w-=curflow;b[v][b[u][i].mp].w+=curflow;
            if(res==flow) break;
        }
        return res;
    }
    int op(){
        int res=0;
        while(bfs()) res+=dfs(s,INF);
        return res;
    }
};
//------------------[template:Dinic]------------------//
struct xor_base{
    int L;
    std::vector<int> p;
    xor_base(int _L):L(_L){p.resize(L+1);}
    void clear(){for(int i=0;i<L;i++) p[i]=0;}
    void print(){for(int i=0;i<L;i++) std::cout<<p[i]<<" ";std::cout<<endl;}
    bool ins(int x){
        for(int i=L-1;i>=0;i--){
            if((1ll<<i)>x) continue;
            if(!p[i]) return p[i]=x,true;
            x^=p[i];
        }
        return false;
    }
    int querymax(int x){for(int i=L-1;i>=0;i--) to_max(x,x^p[i]);return x;}
};
//-----------------[template:xorbase]-----------------//
namespace gaojingdu{
const int Bas=10;
struct Number{
    int L;
    std::vector<int> a;
    Number(int _L):L(_L){
        a.resize(L);
    }
    void print(){
        for(int i=L-1;i>=0;i--) std::cout<<a[i];
    }
    Number operator+(const Number& x)const{
        int l=std::max(L,x.L);
        Number res(l);
        for(int i=0;i<l;i++){
            if(i<L) res.a[i]+=a[i];
            if(i<x.L) res.a[i]+=x.a[i];
        }
        for(int i=0;i<l-1;i++) res.a[i+1]+=res.a[i]/Bas,res.a[i]%=Bas;
        if(res.a[l-1]>Bas) res.a.push_back(res.a[l-1]/Bas),res.a[l-1]%=Bas,res.L++;
        return res;
    }
    Number operator*(const Number& x)const{
        int l=L+x.L-1;
        Number res(l);
        for(int i=0;i<L;i++) for(int j=0;j<x.L;j++) res.a[i+j]+=a[i]*x.a[j];
        for(int i=0;i<l-1;i++) res.a[i+1]+=res.a[i]/Bas,res.a[i]%=Bas;
        while(res.a[l-1]>Bas) res.a.push_back(res.a[l-1]/Bas),res.a[l-1]%=Bas,l++,res.L++;
        return res;
    }
};
Number cst(int x){
    Number res(0);
    while(x) res.a.push_back(x%Bas),res.L++,x/=Bas;
    return res;
}
}//end of namespace
//-----------------[template:gaojing]-----------------//
struct Point{
    int x,y;
    Point operator+(const Point& p)const{return (Point){x+p.x,y+p.y};}
    Point operator-(const Point& p)const{return (Point){x-p.x,y-p.y};}
    int operator*(const Point& p)const{return x*p.y-p.x*y;}
    double getk(){return (double)y/x;}
    void print(){std::cout<<'('<<x<<','<<y<<')'<<' ';}
};
int orient(Point bas,Point p,Point q){return (p-bas)*(q-bas);}
//------------------[template:Point]------------------//
const int mod=998244353;
void add(int& x,int y){x=(x+y)%mod;}
void mul(int& x,int y){x=1ll*x*y%mod;}
int qpow(long long x,int b,int _mod=mod){
    long long res=1;
    while(b){
        if(b&1) res=res*x%_mod;
        x=x*x%_mod;
        b>>=1;
    }
    return res;
}
int getinv(int x){return qpow(x,mod-2);}
struct Comb{
    int N;
    std::vector<int> pw;
    std::vector<int> ipw;
    Comb(int _N):N(_N){
        pw.resize(N);ipw.resize(N);
        pw[0]=1;for(int i=1;i<N;i++) pw[i]=pw[i-1]*i%mod;
        ipw[N-1]=getinv(pw[N-1]);
        for(int i=N-1;i>0;i--) ipw[i-1]=ipw[i]*i%mod;
    }
    int getC(int x,int y){return x<y?0:pw[x]*ipw[y]%mod*ipw[x-y]%mod;}
};
//-------------------[template:mod]-------------------//
struct Matrix{
    int n,m;
    std::vector<std::vector<int> > c;
    Matrix(int N,int M):n(N),m(M){
        c.resize(N);
        for(int i=0;i<N;i++){
            c[i].resize(M);
            for(int j=0;j<M;j++) c[i][j]=0;
        }
    }
    void print(){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++) std::cout<<c[i][j]<<" ";std::cout<<endl;
        }
    }
    int val(int x,int y){return c[x-1][y-1];}
    void to_bas(){
        for(int i=0;i<n;i++) for(int j=0;j<m;j++) c[i][j]=(i==j)?1:0;
    }
    Matrix operator+(const Matrix& mt)const{
        Matrix res(n,m);
        for(int i=0;i<n;i++) for(int j=0;j<m;j++) add(res.c[i][j],c[i][j]+mt.c[i][j]);
        return res;
    }
    Matrix operator*(const Matrix& mt)const{
        Matrix res(n,mt.m);
        for(int k=0;k<m;k++) for(int i=0;i<n;i++) for(int j=0;j<mt.m;j++)
            add(res.c[i][j],c[i][k]*mt.c[k][j]);
        return res;
    }
};
Matrix qpow(Matrix mt,int b){
    Matrix res(mt.n,mt.m);res.to_bas();
    while(b){
        if(b&1) res=res*mt;
        mt=mt*mt;
        b>>=1;
    }
    return res;
}
//-----------------[template:Matrix]-----------------//
//-------------------[template:all]-------------------//
using namespace gaojingdu;
using namespace std;
const int N=2000010;
int n,k,a[N],fa[N],p[N],id[N],cnt,cl[N],q[N],h=1,t;
vector<int> d[N],pos[N];
inline void init(){
    memset(p,1,sizeof(p));
    for(int i=2;i<N/2;i++){
        if(p[i]){
            id[++cnt]=i;
            d[i].push_back(cnt);
            for(int j=2*i;j<N/2;j+=i) p[j]=false,d[j].push_back(cnt);
        }
    }
}
inline int to_id(int i){
    if(i<n) return i+1;
    if(i==n) return 1;
    if(i>n) return i-n+1;
    assert(0);return 0;
}
inline int to_val(int i,int op){
    if(i==1) return n;
    if(op==0) return i-1;
    if(op==1) return i-1+n;
    assert(0);return 0;
}
int finds(int x){return fa[x]==x?x:fa[x]=finds(fa[x]);}
inline void merge(int u,int v){
    int fu=finds(u),fv=finds(v);
    if(fu!=fv) fa[fu]=fv;
}
inline int dis(int u,int v){
    //cout<<"try merge "<<u<<" "<<v<<endl;
    return v-u;
}
inline void solve(int ttt){
    cin>>n>>k;h=1;t=0;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=2*n-1;i++) fa[i]=i;
    for(int i=1;i<=n;i++){
        for(auto x:d[a[i]]){
            if(cl[x]!=ttt) pos[x].clear(),cl[x]=ttt,q[++t]=x;
            pos[x].push_back(to_val(i,0));
            if(i>1) pos[x].push_back(to_val(i,1));
        }
    }
    for(int i=1;i<=t;i++){
        int u=q[i];//factor
        sort(pos[u].begin(),pos[u].end());
        //cout<<u<<" ";
        int lst=pos[u][0];
        for(int j=1;j<pos[u].size();j++){
            int cur=pos[u][j];
            if(dis(lst,cur)<=k) merge(cur,lst);
            lst=cur;
        }
    }
    //cout<<endl;
    for(int i=1;i<2*n;i++) fa[i]=finds(fa[i]);
    int ans=0;
    for(int i=1;i<2*n;i++) if(fa[i]==i) ans++;
    for(int i=1;i<=n;i++) if(a[i]==1) ans+=(i==1?n-1:n-2);
    cout<<ans<<endl;
}
signed main(){
    IOS();
    init();
    int T=1;
    cin>>T;
    for(int i=1;i<=T;i++) solve(i);
}