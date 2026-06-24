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

const int N=100005,M=53;

std::vector<int>p[N],po[N];
std::vector<std::pair<int,ull>>bp[N];
int n,m,d,tm,sm,bm,dfn[N],low[N],st[N],bl[N],val[N][M],deg[N],q2[N],f[N][M];
char o[N][M],ok[N][M];
ll ov[N],kv[N];
pii q[N*M];

inline void dfs(int x)
{
	dfn[x]=low[x]=++tm;
	st[sm++]=x;
	foe(i,p[x])
	{
		if(!dfn[*i])
		{
			dfs(*i);
			repl(low[x],low[*i]);
		}
		else if(!bl[*i])
		{
			repl(low[x],dfn[*i]);
		}
	}
	if(low[x]==dfn[x])
	{
		for(bm++;;)
		{
			bl[st[--sm]]=bm;
			po[bm].pb(st[sm]);
			if(st[sm]==x)break;
		}
	}
}

int main()
{
	//freopen("in.txt","r",stdin);
	in,n,m,d;
	fo1(i,m)
	{
		int x,y;
		in,x,y;
		p[x].pb(y);
	}
	fo1(i,n)in,o[i];
	fo1(i,n)fo0(j,d)o[i][j]-=48;
	fo1(i,n)
	{
		ov[i]=0;
		fo0(j,d)ov[i]|=(ull)o[i][j]<<j;
	}
	dfs(1);
	std::map<pii,std::vector<pii>>tt;
	fo1(i,n)if(dfn[i])
	{
		std::vector<int>np;
		foe(j,p[i])
		{
			if(bl[*j]==bl[i])np.pb(*j);
			//else bp[bl[i]].pb(bl[*j]);
			else tt[mp(bl[i],bl[*j])].pb(mp(i,*j));
		}
		p[i]=np;
	}
	fo1(i,bm)
	{
		//out,i,':';foe(j,po[i])out,*j,' ';out,'\n';
		int x=po[i][0],qe=0;
		ok[x][0]=1;
		q[qe++]=mp(x,0);
		for(int j=0;j<qe;j++)
		{
			int a=q[j].xx,b=(q[j].yy+1)%d;
			foe(k,p[a])if(!ok[*k][b])
			{
				ok[*k][b]=1;
				q[qe++]=mp(*k,b);
			}
		}
		foe(j,po[i])
		{
			fo0(k,d)kv[*j]|=(ull)ok[*j][k]<<k;
		}
		fo0(j,d)
		{
			int ta=0;
			foe(k,po[i])
			{
				ta+=bool(ov[*k]&kv[*k]);
				//kv[*k]=(kv[*k]>>1)|((kv[*k]&1)<<d-1);
				kv[*k]=((kv[*k]<<1)&((1ull<<d)-1))|(kv[*k]>>d-1);
			}
			val[i][j]=ta;
		}
	}
	//fo1(i,n){fo0(j,d)out,(int)ok[i][j],' ';out,'\n';}out,'\n';
	//fo1(i,bm){fo0(j,d)out,val[i][j],' ';out,'\n';}
	foe(i,tt)
	{
		int x=i->xx.xx,y=i->xx.yy;
		//out,'/',x,' ',y,'\n';
		std::vector<pii>&ttt=i->yy;
		ull mask=0;
		foe(j,ttt)
		{
			int a=j->xx,b=j->yy;
			fo0(u,d)if(ok[a][u])fo0(v,d)if(ok[b][v])
			{
				int x=1+u-v;
				if(x<0)x+=d;else if(x>=d)x-=d;
				mask|=1ull<<x;
			}
		}
		//out,'/',x,' ',y,' ',mask,'\n';
		bp[x].pb(mp(y,mask));
		deg[y]++;
	}
	int qe=0;
	fo1(i,bm)if(!deg[i])q2[qe++]=i;
	fo0(i,bm)foe(j,bp[q2[i]])if(!--deg[j->xx])q2[qe++]=j->xx;
	fo1(i,bm)fo0(j,d)f[i][j]=-N;
	fo0(j,d)if(ok[1][j])f[bl[1]][(d-j)%d]=0;
	int ans=0;
	fo0(i,bm)
	{
		int x=q2[i];
		fo0(j,d)repr(ans,f[x][j]+=val[x][j]);
		foe(j,bp[x])
		{
			int y=j->xx;
			fo0(k,d)if(j->yy>>k&1)
			{
				int u=k;
				fo0(l,d)
				{
					repr(f[y][u],f[x][l]);
					if(++u==d)u=0;
				}
			}
		}
		//out,'/',x,'\n';
		//fo0(j,d)out,f[x][j],' ';out,'\n';
	}
	out,ans,'\n';
}