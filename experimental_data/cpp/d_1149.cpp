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

const int N=71,inf=0x3f3f3f3f;

std::vector<int>pa[N],pb[N];
int n,m,a,b,tot,da[N][N],db[N][N],d[N][N],ans[N],id[N],q[128],f[1<<17|7][N];
bool vis[N];

int main()
{
	in,n,m,a,b;
	mset(da,0x3f);
	mset(db,0x3f);
	fo1(i,m)
	{
		int x,y,w;
		in,x,y,w;
		if(w==a)pa[x].pb(y),pa[y].pb(x),da[x][y]=da[y][x]=1;
		//else pb[x].pb(y),pb[y].pb(x),db[x][y]=db[y][x]=1;
		else db[x][y]=db[y][x]=1;
	}
	fo1(i,n)da[i][i]=0;
	fo1(i,n)fo1(j,n)fo1(k,n)repl(da[j][k],da[j][i]+da[i][k]);
	fo1(i,n)fo1(j,n)if(da[i][j]==inf&&db[i][j]!=inf)pb[i].pb(j);
	/*fo1(i,n)fo1(j,n)if(da[i][j]!=inf)db[i][j]=inf;
	//fo1(i,n)db[i][i]=0;
	//fo1(i,n)fo1(j,n)fo1(k,n)repl(db[j][k],db[j][i]+db[i][k]);
	fo1(i,n)fo1(j,n)
	{
		if(da[i][j]!=inf)d[i][j]=da[i][j]*a;
		else if(db[i][j]!=inf)d[i][j]=db[i][j]*b;
		else d[i][j]=inf;
	}
	fo1(i,n)fo1(j,n)fo1(k,n)if(da[j][k]==inf)repl(d[j][k],d[j][i]+d[i][k]);*/
	/*fo1(i,n)
	{
		//if(da[1][i]!=inf)ans[i]=da[1][i]*a;
		//else ans[i]=
		ans[i]=d[1][i];
	}
	fo1(i,n)out,ans[i],' ';out,'\n';*/
	fo1(i,n)if(!id[i])
	{
		int c=0;
		fo1(j,n)if(da[i][j]!=inf)c++;
		if(c>=4)
		{
			tot++;
			fo1(j,n)if(da[i][j]!=inf)id[j]=tot;
		}
	}
	mset(ans,0x3f);
	mset(f,0x3f);
	if(id[1])f[1][1]=0;
	else f[0][1]=0;
	fo0(i,1<<tot)
	{
		fo1(j,n)vis[j]=1,q[j-1]=j;
		int qb=0,qe=n;
		while(qb<qe)
		{
			int t=q[qb++&127];
			foe(j,pa[t])if(repl(f[i][*j],f[i][t]+a)&&!vis[*j])q[qe++&127]=*j;
			foe(j,pb[t])if(!id[*j]&&repl(f[i][*j],f[i][t]+b)&&!vis[*j])q[qe++&127]=*j;
			vis[t]=0;
		}
		int c=0;
		fo1(j,n)
		{
			//foe(k,pa[j])repl(f[
			foe(k,pb[j])
			{
				//if(!id[*k])repl(f[i][*k],f[i][j]
				int t=id[*k];
				if(t)
				{
					--t;
					if(~i>>t&1)repl(f[i|1<<t][*k],f[i][j]+b);
				}
			}
			repl(ans[j],f[i][j]);
		}
	}
	fo1(i,n)out,ans[i],' ';out,'\n';
}