#include <cstdio>

#include <cstring>

#include <algorithm>

#include <string>

#include <iostream>

#include <cmath>

#include <ctime>

#include <cctype>

#include <queue>

#include <stack>

#include <map>

#include <set>

#include <bitset>

#include <cassert>



using namespace std;



#define prt(x) cout<<#x<<":"<<x<<" "

#define prtn(x) cout<<#x<<":"<<x<<endl

#define shut assert(0)

#define when printf("%.2f\n",1.0*clock()/CLOCKS_PER_SEC)

#define rep(i,s,t) for(int i=s,i##_=t;i<i##_;++i)

#define per(i,s,t) for(int i=(t)-1,i##_=s;i>=i##_;--i)

#define inf (1<<30)

#define INF (1LL<<62)

#define sqr(x) ((x)*(x))

#define pb push_back

#define NOO puts("-1"),0

#define ALL(x) (x).begin(),(x).end()

#define SZ(x) (int)(x).size()



typedef long long ll;

typedef double db;

typedef vector<int> VI;

typedef vector<VI> MT;

typedef vector<double> VD;

typedef vector<string> VS;

struct ii

{

	int x,y;

	ii(int x=0,int y=0):x(x),y(y){}

	bool operator<(const ii &a)const{if(x!=a.x)return x<a.x;return y<a.y;}

	bool operator==(const ii&a)const{return x==a.x&&y==a.y;}

	ii friend operator+(ii a,ii b){return ii(a.x+b.x,a.y+b.y);}

	ii friend operator-(ii a,ii b){return ii(a.x-b.x,a.y-b.y);}

};

 

//ll memory freopen



template<class T>void sc(T &x)

{

	x=0;char c;int f=1;

	while(c=getchar(),c<48)if(c=='-')f=-1;

	do x=x*10+(c^48);

	while(c=getchar(),c>47);

	x*=f;

}

template<class T>void nt(T x)

{

	if(!x)return;

	nt(x/10);putchar(x%10+'0');

}

template<class T>void pt(T x)

{

	if(x<0)putchar('-'),x=-x;

	if(!x)putchar('0');else nt(x);

}

template<class T>void pts(T x)

{

	pt(x);putchar(' ');

}

template<class T>void ptn(T x)

{

	pt(x);putchar('\n');

}

template<class v>void pp(v x,int y)

{

	static char ch[]={" \n"};

	pt(x);putchar(ch[y]);

}

template<class T>void PP(T *x,int y)

{

	rep(i,0,y)pp(x[i],i==y-1);

}

template<class T>void Max(T &x,T y){if(x<y)x=y;}

template<class T>void Min(T &x,T y){if(x>y)x=y;}



/* template ends here  */



const int maxn=100005;

const int maxm=400005;

const int mod=1e9+7;

typedef int arrn[maxn];

typedef int arrm[maxm];



int n,m;

arrm point,nextp;ll aval[maxm];

arrn head;

int ecnt;

void ins(int u,int v,ll w)

{

	point[++ecnt]=v;

	nextp[ecnt]=head[u];

	aval[ecnt]=w;

	head[u]=ecnt;

}

bool vis[maxn],inq[maxn];

ll v[maxn];

ll d[maxm],tot;

ll bin[maxm];

int s[maxn],cnt;

void dfs(int x)

{

	inq[x]=vis[x]=true;

	s[cnt++]=x;

	for(int i=head[x];i;i=nextp[i])

	{

		int to=point[i];

		if(inq[to])

		{

			ll vv=v[to]^v[x]^aval[i];

			if(vv)d[tot++]=vv;

		}

		else if(!vis[to])

		{

			v[to]=v[x]^aval[i];

			dfs(to);

		}

	}

	inq[x]=0;

}

void cal()

{

	int tt=0;

	for(ll i=1LL<<62;i;i>>=1)

	{

		bool ok=0;

		rep(k,tt,tot)

		if(d[k]&i)

		{

			swap(d[tt],d[k]);

			ok=1;break;

		}

		if(!ok)continue;

		rep(k,0,tot)if(k!=tt&&(d[k]&i))

			d[k]^=d[tt];

		tt++;

	}

	tot=tt;

}

int main()

{

//	freopen("pro.in","r",stdin);

//	freopen("chk.out","w",stdout);

	sc(n);sc(m);

	bin[0]=1;

	rep(i,1,max(n,m)+1)bin[i]=bin[i-1]*2%mod;

	rep(i,0,m)

	{

		int u,v;ll w;

		sc(u);sc(v);sc(w);

		ins(u,v,w);

		ins(v,u,w);

	}

	ll ans=0;

	rep(i,1,n+1)if(!vis[i])

	{

		tot=0;cnt=0;

		dfs(i);cal();

		rep(pos,0,62)

		{

			ll A[2]={0};

			rep(i,0,cnt)

				A[v[s[i]]>>pos&1]++;

			

			bool ok=0;

			rep(i,0,tot)if(d[i]>>pos&1)ok=1;

			ll res=0,tmp,k;

			{

				tmp=(A[0]*(A[0]-1)+A[1]*(A[1]-1))/2%mod;

				if(ok)k=bin[tot-1];

				else k=0;

				res=tmp*k%mod;

			}

			{

				tmp=A[0]*A[1]%mod;

				if(ok)k=bin[tot-1];

				else k=bin[tot];

				res=(res+tmp*k)%mod;

			}

			ans=(ans+res*bin[pos])%mod;

		}

	}

	ptn(ans);

	return 0;

}