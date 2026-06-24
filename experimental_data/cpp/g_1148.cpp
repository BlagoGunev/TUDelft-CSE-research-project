#include<bits/stdc++.h>

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef double lf;
typedef long double llf;
typedef std::pair<int,int> pii;

#define xx first
#define yy second

template<typename T> inline T max(T a,T b){return a>b?a:b;}
template<typename T> inline T min(T a,T b){return a<b?a:b;}
template<typename T> inline T abs(T a){return a>0?a:-a;}
template<typename T> inline bool repr(T &a,T b){return a<b?a=b,1:0;}
template<typename T> inline bool repl(T &a,T b){return a>b?a=b,1:0;}
template<typename T> inline T gcd(T a,T b){T t;if(a<b){while(a){t=a;a=b%a;b=t;}return b;}else{while(b){t=b;b=a%b;a=t;}return a;}}
template<typename T> inline T sqr(T x){return x*x;}
#define mp(a,b) std::make_pair(a,b)
#define pb push_back
#define I __attribute__((always_inline))inline
#define mset(a,b) memset(a,b,sizeof(a))
#define mcpy(a,b) memcpy(a,b,sizeof(a))

#define fo0(i,n) for(int i=0,i##end=n;i<i##end;i++)
#define fo1(i,n) for(int i=1,i##end=n;i<=i##end;i++)
#define fo(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define fd0(i,n) for(int i=(n)-1;~i;i--)
#define fd1(i,n) for(int i=n;i;i--)
#define fd(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define foe(i,x)for(__typeof((x).end())i=(x).begin();i!=(x).end();++i)
#define fre(i,x)for(__typeof((x).rend())i=(x).rbegin();i!=(x).rend();++i)

struct Cg{I char operator()(){return getchar();}};
struct Cp{I void operator()(char x){putchar(x);}};
#define OP operator
#define RT return *this;
#define UC unsigned char
#define RX x=0;UC t=P();while((t<'0'||t>'9')&&t!='-')t=P();bool f=0;\
if(t=='-')t=P(),f=1;x=t-'0';for(t=P();t>='0'&&t<='9';t=P())x=x*10+t-'0'
#define RL if(t=='.'){lf u=0.1;for(t=P();t>='0'&&t<='9';t=P(),u*=0.1)x+=u*(t-'0');}if(f)x=-x
#define RU x=0;UC t=P();while(t<'0'||t>'9')t=P();x=t-'0';for(t=P();t>='0'&&t<='9';t=P())x=x*10+t-'0'
#define TR *this,x;return x;
I bool IS(char x){return x==10||x==13||x==' ';}template<typename T>struct Fr{T P;I Fr&OP,(int&x)
{RX;if(f)x=-x;RT}I OP int(){int x;TR}I Fr&OP,(ll &x){RX;if(f)x=-x;RT}I OP ll(){ll x;TR}I Fr&OP,(char&x)
{for(x=P();IS(x);x=P());RT}I OP char(){char x;TR}I Fr&OP,(char*x){char t=P();for(;IS(t);t=P());if(~t){for(;!IS
(t)&&~t;t=P())*x++=t;}*x++=0;RT}I Fr&OP,(lf&x){RX;RL;RT}I OP lf(){lf x;TR}I Fr&OP,(llf&x){RX;RL;RT}I OP llf()
{llf x;TR}I Fr&OP,(uint&x){RU;RT}I OP uint(){uint x;TR}I Fr&OP,(ull&x){RU;RT}I OP ull(){ull x;TR}};Fr<Cg>in;
#define WI(S) if(x){if(x<0)P('-'),x=-x;UC s[S],c=0;while(x)s[c++]=x%10+'0',x/=10;while(c--)P(s[c]);}else P('0')
#define WL if(y){lf t=0.5;for(int i=y;i--;)t*=0.1;if(x>=0)x+=t;else x-=t,P('-');*this,(ll)(abs(x));P('.');if(x<0)\
x=-x;while(y--){x*=10;x-=floor(x*0.1)*10;P(((int)x)%10+'0');}}else if(x>=0)*this,(ll)(x+0.5);else *this,(ll)(x-0.5);
#define WU(S) if(x){UC s[S],c=0;while(x)s[c++]=x%10+'0',x/=10;while(c--)P(s[c]);}else P('0')
template<typename T>struct Fw{T P;I Fw&OP,(int x){WI(10);RT}I Fw&OP()(int x){WI(10);RT}I Fw&OP,(uint x){WU(10);RT}
I Fw&OP()(uint x){WU(10);RT}I Fw&OP,(ll x){WI(19);RT}I Fw&OP()(ll x){WI(19);RT}I Fw&OP,(ull x){WU(20);RT}I Fw&OP()
(ull x){WU(20);RT}I Fw&OP,(char x){P(x);RT}I Fw&OP()(char x){P(x);RT}I Fw&OP,(const char*x){while(*x)P(*x++);RT}
I Fw&OP()(const char*x){while(*x)P(*x++);RT}I Fw&OP()(lf x,int y){WL;RT}I Fw&OP()(llf x,int y){WL;RT}};Fw<Cp>out;

const int N=100007,M=10000007;

int n,k,pc,uv,s[N],mu[M],lo[M],p[M/10],f[8],g[256],c[M],h[N],o[N];
pii st[N];
std::vector<int>u[262333];

inline void setr(int l,int r,int vt)
{
	for(int i=l,nxt;i<=r;i=nxt)
	{
		int t=0,v=s[i];
		while(v!=1)
		{
			if(!t||f[t-1]!=lo[v])f[t++]=lo[v];
			v/=lo[v];
		}
		nxt=i+1;
		while(nxt<=r&&s[nxt]==s[i])nxt++;
		int tv=(nxt-i)*vt;
		g[0]=1;
		fo1(j,(1<<t)-1)
		{
			g[j]=g[j&j-1]*f[__builtin_ctz(j)];
			c[g[j]]+=tv;
		}
	}
}

inline void dfs(int x,int l,int r)
{
	if(!u[x].size())return;
	//out,"dfs:",x,' ',l,' ',r,' ',u[x].size(),'\n';
	if(l==r)
	{
		foe(j,u[x])o[*j]=l;
		return;
	}
	int mid=(l+r)>>1;
	setr(l,mid,1);
	int lst=-1,lstv=-1,len=mid-l+1;
	foe(i,u[x])
	{
		if(lst==s[*i])
		{
			u[x<<1|lstv].pb(*i);
			continue;
		}
		lst=s[*i];
		{
			int t=0,v=lst;
			while(v!=1)
			{
				if(!t||f[t-1]!=lo[v])f[t++]=lo[v];
				v/=lo[v];
			}
			g[0]=1;
			int sum=0;
			fo1(j,(1<<t)-1)
			{
				if(j)g[j]=g[j&j-1]*f[__builtin_ctz(j)];
				sum+=c[g[j]]*(__builtin_popcount(j)&1?1:-1);
			}
			//out,'/',sum,'\n';
			if(sum!=len)u[x<<1].pb(*i),lstv=0;
			else u[x<<1|1].pb(*i),lstv=1;
		}
	}
	u[x].clear();
	setr(l,mid,-1);
	dfs(x<<1,l,mid);
	dfs(x<<1|1,mid+1,r);
}

int main()
{
	fo0(i,M)mu[i]=2;
	mu[1]=1;
	fo(i,2,M-1)
	{
		if(2==mu[i])mu[i]=-1,p[pc++]=i,lo[i]=i;
		for(int j=0;i*p[j]<M;j++)
		{
			lo[i*p[j]]=p[j];
			mu[i*p[j]]=-mu[i];
			if(i%p[j]==0)
			{
				mu[i*p[j]]=0;
				break;
			}
		}
	}
	in,n,k;
	fo1(i,n)
	{
		in,st[i].xx;
		st[i].yy=i;
	}
	std::sort(st+1,st+n+1);
	fo1(i,n)s[i]=st[i].xx;
	setr(1,n,1);
	fo1(i,n)
	{
		if(i>1&&s[i]==s[i-1])
		{
			h[i]=h[i-1];
			continue;
		}
		int t=0,v=s[i];
		while(v!=1)
		{
			if(!t||f[t-1]!=lo[v])f[t++]=lo[v];
			v/=lo[v];
		}
		g[0]=1;
		int sum=0;
		fo1(j,(1<<t)-1)
		{
			if(j)g[j]=g[j&j-1]*f[__builtin_ctz(j)];
			sum+=c[g[j]]*(__builtin_popcount(j)&1?1:-1);
		}
		//o[i]=sum==n;
		h[i]=sum;
		//out,i,' ',sum,'\n';
	}
	setr(1,n,-1);
	int tt=0;
	fo1(i,n)tt+=h[i]==n;
	//out,'/',tt,' ',k,'\n';
	if(tt>=k)
	{
		fo1(i,n)if(h[i]==n&&k)
		{
			k--;out,st[i].yy,' ';
		}
		out,'\n';
		return 0;
	}
	fo1(i,n)if(h[i]!=n)
	{
		if(h[i]!=n-1)uv=i;
		u[1].pb(i);
	}
	dfs(1,1,n);
	//fo1(i,n)out,s[i],' ';out,'\n';
	//fo1(i,n)out,o[i],' ';out,'\n';
	//fo1(i,n)out,gcd(s[i],s[o[i]]),' ';out,'\n';
	fo1(i,n)if(h[i]!=n)assert(o[i]);
	bool all1=1;
	fo1(i,n)if(h[i]!=n-1&&h[i]!=n)all1=0;
	if(all1)
	{
		std::set<int>tu;
		fo1(i,n)
		{
			if((h[i]==n||!tu.count(i))&&k)
			{
				k--;
				tu.insert(o[i]);
				out,st[i].yy,' ';
			}
		}
		out,'\n';
		return 0;
	}
	int uv2=0;
	std::set<int>tt2;
	fd1(i,n)if(h[i]!=n)
	{
		if(tt2.count(i))continue;
		tt2.insert(o[i]);
		if(o[o[i]]!=i)
		{
			uv=o[i],uv2=i;
			break;
		}
	}
	assert(uv2);
	std::set<int>ans;
	ans.insert(uv);
	ans.insert(o[uv]);
	fo1(i,n)if(h[i]!=n&&i!=uv2)
	{
		int na=ans.size()+(!ans.count(i))+(!ans.count(o[i]));
		if(na<=k)
		{
			ans.insert(i);
			ans.insert(o[i]);
		}
	}
	if(ans.size()!=k)ans.insert(uv2);
	foe(i,ans)out,st[*i].yy,' ';out,'\n';
}