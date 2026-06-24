#include<map>

#include<set>

#include<cmath>

#include<queue>

#include<stack>

#include<ctime>

#include<vector>

#include<cstdio>

#include<string>

#include<bitset>

#include<cstdlib>

#include<cstring>

#include<iostream>

#include<algorithm>

#include<functional>

using namespace std;

#define X first

#define Y second

#define mkp make_pair

#define lson (o<<1)

#define rson ((o<<1)|1)

#define mid (l+(r-l)/2)

#define sz() size()

#define pb(v) push_back(v)

#define all(o) (o).begin(),(o).end()

#define clr(a,v) memset(a,v,sizeof(a))

#define bug(a) cout<<#a<<" = "<<a<<endl

#define rep(i,a,b) for(int i=a;i<(b);i++)

#define scf scanf

#define prf printf



typedef long long LL;

typedef vector<int> VI;

typedef pair<int,int> PII;

typedef vector<pair<int,int> > VPII;



const int INF=0x3f3f3f3f;

const LL INFL=0x3f3f3f3f3f3f3f3fLL;

const double eps=1e-8;

const double PI = acos(-1.0);



//start----------------------------------------------------------------------



const int maxn=222;



struct Edge{

    int u,v,ne,flag;

    Edge(int u,int v,int ne):u(u),v(v),ne(ne),flag(0){}

    Edge(){}

}egs[maxn*2];



int n;

int head[maxn],tot;



void addEdge(int u,int v){

    egs[tot]=Edge(u,v,head[u]);

    head[u]=tot++;

}



void dfs(int u,int fa,int dep,int& ret,int& ma){

    if(dep>ma){ ret=u,ma=dep; }

    int p=head[u];

    while(p!=-1){

        Edge& e=egs[p];

        if(!e.flag&&e.v!=fa){

            dfs(e.v,u,dep+1,ret,ma);

        }

        p=e.ne;

    }

}



int solve(int u){

    int ret=0;

    int v=-1,ma=-1;

    dfs(u,-1,0,v,ma);

    u=v;

    v=-1,ma=-1;

    dfs(u,-1,0,v,ma);

    return ma;

}



void init(){

    clr(head,-1);

    tot=0;

}



int main() {

    scf("%d",&n);

    init();

    rep(i,0,n-1){

        int u,v;

        scf("%d%d",&u,&v);

        addEdge(u,v);

        addEdge(v,u);

    }

    int ans=0;

    for(int i=0;i<tot;i+=2){

        egs[i].flag=egs[i^1].flag=1;

        int x=solve(egs[i].u);

        int y=solve(egs[i].v);

        ans=max(ans,x*y);

        egs[i].flag=egs[i^1].flag=0;

    }

    prf("%d\n",ans);

    return 0;

}



//end-----------------------------------------------------------------------