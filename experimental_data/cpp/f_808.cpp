#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 205
#define vg vector<Edge>

inline ll input(void)
{
    char t;
    ll x=0;
    int neg=0;
    t=getchar();
    while((t<48 || t>57) && t!='-')
	t=getchar();
    if(t=='-')
    {neg=1; t=getchar();}
    while(t>=48 && t<=57)
    {
	x=(x<<3)+(x<<1)+t-48;
	t=getchar();
    }
    if (neg) x=-x;
    return x;
}

inline void output(ll x)
{
    char a[20];
    int i=0,j;
    a[0]='0';
    if (x<0) {putchar('-'); x=-x;}
    if (x==0) putchar('0');
    while(x)
    {
	a[i++]=x%10+48;
	x/=10;
    }
    for(j=i-1;j>=0;j--)
    {
	putchar(a[j]);
    }
    putchar('\n');
}

int N,M,src,sink;
int dist[MAXN],work[MAXN];
struct Edge
{
    int to,rev;
    ll int cap,flow;
};

vector<vg> g;
const ll INF=1e18;
//Adds Unidirectional edge from s to t having capacity c
void addEdge(int s,int t,ll int c)
{
    Edge a={t,g[t].size(),c,0LL};
    Edge b={s,g[s].size(),0,0LL};
    g[s].push_back(a);
    g[t].push_back(b);
}

bool bfs()
{
    memset(dist,-1,sizeof(dist));
    dist[src]=0;
    queue<int> q;
    q.push(src);
    while(!q.empty())
    {
	int u=q.front();
	q.pop();
	for(int i=0;i<g[u].size();i++)
	{
	    Edge &e=g[u][i];
	    if(e.flow>=e.cap)
		continue;
	    if(dist[e.to]>=0)
		continue;
	    dist[e.to]=dist[u]+1;
	    q.push(e.to);
	}
    }
    return (dist[sink]>=0);
}
ll int dfs(int v,ll int f)
{
    if(v==sink)
	return f;
    for(int &i=work[v];i<(int)g[v].size();i++)
    {
	Edge &e=g[v][i];
	if(g[v][i].flow>=g[v][i].cap)
	    continue;
	int u=g[v][i].to;
	if(dist[u]!=(dist[v]+1))
	    continue;
	ll int df=dfs(u,min(f,g[v][i].cap-g[v][i].flow));
	if(df>0)
	{
	    g[v][i].flow+=df;
	    g[u][g[v][i].rev].flow-=df;
	    return df;
	}
    }
    return 0;
}
ll int Dinic(int _src,int _sink)
{
    src=_src;
    sink=_sink;
    ll int res=0;
    while(bfs())
    {
	memset(work,0,sizeof(work));
	while(ll int add = dfs(src,INF) )
	{
	    res+=add;
	}
    }
    return res;
}
//Input Order
//n m
//m edges u v c
//s t
const int MX=2e5+5;
bool isprime[MX];
int p[MAXN];
int c[MAXN];
int l[MAXN];
void init()
{
    memset(isprime,true,sizeof(isprime));
    isprime[1]=isprime[0]=false;
    for(int i=2;i<MX;i++)
    {
	if(isprime[i]==false)
	    continue;
	for(int j=2*i;j<MX;j+=i)
	    isprime[j]=false;
    }
}
bool valid(int x,int n,int k)
{
    //g.clear();
    //g.resize(2*n+5);
    for(int i=0;i<=2*n+1;i++)
	g[i].clear();
    int _src=0;
    int _sink=2*n+1;
    int sum=0;
    for(int i=1;i<=n;i++)
    {
	if(l[i]<=x)
	{
	    sum+=p[i];
	    addEdge(_src,i,p[i]);
	    addEdge(i+n,_sink,p[i]);
	}
    }
    sum=sum*2;
    for(int i=1;i<=n;i++)
    {
	if(l[i]>x)
	    continue;
	for(int j=i+1;j<=n;j++)
	{
	    if(l[j]>x)
		continue;
	    if(!isprime[c[i]+c[j]])
		continue;
	    //add the edge
	    addEdge(i,n+j,INF);
	    addEdge(j,n+i,INF);
	}
    }
    int flow=Dinic(_src,_sink);
    //cout<<x<<" "<<flow<<" "<<sum<<endl;
    sum-=flow;
    sum/=2;
    if(sum>=k)
	return true;
    else return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    init();
    //N=input();
    cin>>N;
    int k;
    //k=input();
    cin>>k;
    //M=input();
    int n=N;
    for(int i=1;i<=n;i++)
    {
	cin>>p[i]>>c[i]>>l[i];
    }
    int lo=1,hi=n;
    int ans=n+1;
    g.resize(2*n+5);
    while(lo<=hi)
    {
	int m=(lo+hi)/2;
	if(valid(m,n,k))
	{
	    ans=min(ans,m);
	    hi=m-1;
	}
	else lo=m+1;
    }
    if(ans==(n+1))
	ans=-1;
    cout<<ans<<endl;
    return 0;
}