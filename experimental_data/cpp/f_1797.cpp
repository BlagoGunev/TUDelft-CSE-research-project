#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math") //
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
#include<bits/stdc++.h>
using namespace std;
namespace io
{
	const int size = (1 << 20) + 1;
	char buf[size], *p1 = buf, *p2 = buf;
	char buffer[size];
	int op1 = -1;
	const int op2 = size - 1;
	struct FastIO
	{
		inline char readchar()
		{
			return p1 != p2 ? *p1++ : p1 == (p2 = (p1 = buf) + fread(buf, 1, size - 1, stdin)) ? EOF
																							   : *p1++;
		}	
// #ifndef ONLINE_JUDGE
// #define readchar getchar
// #endif
		inline char rc()
		{
			char c=readchar();
			while(c<32 || c==127) c=readchar();
			return c;
		}
		inline void flush()
		{
			fwrite(buffer, 1, op1 + 1, stdout), op1 = -1;
		}
		inline void writechar(const char &x)
		{
			if (op1 == op2)
				flush();
			buffer[++op1] = x;
		}
		inline int readint()
		{
			int s = 1, x = 0;
			char c = readchar();
			while (c <= 32)
			{
				c = readchar();
			}
			if (c == '-')
			{
				s = -1, c = readchar();
			}
			while ('0' <= c && c <= '9')
			{
				x = x * 10 + c - '0';
				c = readchar();
			}
			return x * s;
		}
		inline int readuint()
		{
			int x = 0;
			char c = readchar();
			while (c <= 32)
			{
				c = readchar();
			}
			while ('0' <= c && c <= '9')
			{
				x = x * 10 + c - '0';
				c = readchar();
			}
			return x;
		}
		inline void writeint(int x)
		{
			if (x < 0)
			{
				writechar('-'), x = -x;
			}
			char s[24];
			int n = 0;
			while (x || !n)
			{
				s[n++] = '0' + x % 10, x /= 10;
			}
			while (n--)
			{
				writechar(s[n]);
			}
		}
		inline long long readlonglong()
		{
			long long x = 0, s = 1;
			char c = readchar();
			while (c <= 32)
			{
				c = readchar();
			}
			if (c == '-')
			{
				s = -1, c = readchar();
			}
			while ('0' <= c && c <= '9')
			{
				x = x * 10 + c - '0';
				c = readchar();
			}
			return x * s;
		}
		inline unsigned long long readulonglong()
		{
			unsigned long long x = 0;
			char c = readchar();
			while (c <= 32)
			{
				c = readchar();
			}
			while ('0' <= c && c <= '9')
			{
				x = x * 10 + c - '0';
				c = readchar();
			}
			return x;
		}
		inline void writelonglong(long long x)
		{
			if (x < 0)
			{
				writechar('-'), x = -x;
			}
			char s[25];
			int n = 0;
			while (x || !n)
			{
				s[n++] = '0' + x % 10, x /= 10;
			}
			while (n--)
			{
				writechar(s[n]);
			}
		}
		inline void writeulonglong(unsigned long long x)
		{
			char s[25];
			int n = 0;
			while (x || !n)
			{
				s[n++] = '0' + x % 10, x /= 10;
			}
			while (n--)
			{
				writechar(s[n]);
			}
		}
		inline int readstring(char *s)
		{
			int cnt = 0;
			char c = readchar();
			while (c <= 32)
			{
				c = readchar();
			}
			while (c > 32)
			{
				*s++ = c, ++cnt;
				c = readchar();
			}
			return *s = 0, cnt;
		}
		inline void writestring(const char *s)
		{
			while (*s)
			{
				writechar(*s++);
			}
		}
		inline double readdouble()
		{
			int zheng = 0, fuhao = 1;
			double xiao = 0, chushu = 10;
			char c;
			while ((c = readchar()) < '0' || c > '9')
			{
				if (c == '-')
				{
					fuhao = -1;
				}
			}
			while (c >= '0' && c <= '9')
			{
				zheng = zheng * 10 + c - '0';
				c = readchar();
			}
			if (c != '.')
			{
				return fuhao * zheng;
			}
			while ((c = readchar()) >= '0' && c <= '9')
			{
				xiao += (c - '0') / chushu;
				chushu *= 10;
			}
			return fuhao * (zheng + xiao);
		}
	} io;
#define readc io::io.rc
#define writec io::io.writechar
#define read io::io.readint
#define readu io::io.readuint
#define write io::io.writeint
#define readl io::io.readlonglong
#define readlu io::io.readulonglong
#define writel io::io.writelonglong
#define writelu io::io.writeulonglong
#define reads io::io.readstring
#define writes io::io.writestring
#define readd io::io.readdouble
#define flush io::io.flush
} using namespace io;
int n,m;
vector<int> e[200010];
bool vis[200010];
int siz[200010],allnode,ax[200010],nowroot;
void get_root(int u,int fa)
{
	siz[u]=1,ax[u]=0;
	for(int v:e[u])
	{
		if(v==fa || vis[v]) continue;
		get_root(v,u);
		siz[u]+=siz[v];
		ax[u]=max(ax[u],siz[v]);
	}
	ax[u]=max(ax[u],allnode-siz[u]);
	if(ax[nowroot]>=ax[u]) nowroot=u;
}
struct Bit
{
	int tree[200010];
	int tot=0,cl[200010];
	void upd(int wz)
	{
        cl[++tot]=wz;
		for(; wz<=2e5+5; wz+=wz&-wz) ++tree[wz];
	}
	int get_sum(int wz)
	{
		int sum=0;
		for(; wz!=0; wz-=wz&-wz) sum+=tree[wz];
		return sum;
	}
	void clear()
	{
		for(int i=1; i<=tot; ++i)
        {
            for(int j=cl[i]; j<=2e5+5; j+=j&-j) tree[j]=0;
        }
		tot=0;
	}
} bit;
long long ans=0;
int nowf,tot;
struct Cdq
{
    int a,b,op;
} c[400010],d[400010];
inline bool cmp(const Cdq &x,const Cdq &y) { return x.a!=y.a?x.a<y.a:x.op<y.op; }
int bitall;
void dfs1(int u,int fa,int in,int ax,bool op)
{
	in=min(in,u),ax=max(ax,u);
	if(!op)
	{
		if(u>in) bit.upd(ax),++bitall;
		else c[++tot]={ax,u,1};
	}
	else
	{
		if(u<ax) bit.upd(in),++bitall;
		else c[++tot]={u,in,1};
	}
	for(int v:e[u])
	{
		if(v==fa || vis[v]) continue;
		dfs1(v,u,in,ax,op);
	}
}
void dfs2(int u,int fa,int in,int ax,bool op)
{
	in=min(in,u),ax=max(ax,u);
	if(!op && u==ax) ans+=bit.get_sum(u-1)*nowf,c[++tot]={u-1,in+1,2};
	if(op && u==in) ans+=(bitall-bit.get_sum(u))*nowf,c[++tot]={ax-1,u+1,2};
	for(int v:e[u])
	{
		if(v==fa || vis[v]) continue;
		dfs2(v,u,in,ax,op);
	}
}
void dfs3(int now,int u,int fa,int in,int ax)
{
	in=min(in,u),ax=max(ax,u);
	ans+=(now==in && u!=ax)+(now==ax && u!=in)+(u==in && now!=ax)+(u==ax && now!=in);
	for(int v:e[u])
	{
		if(v==fa || vis[v]) continue;
		dfs3(now,v,u,in,ax);
	}
}
int ccnt[1<<9];
void sort()
{
	if(tot<=50) sort(c+1,c+tot+1,cmp);
	else
	{
		memset(ccnt,0,sizeof(ccnt));
		for(int i=1; i<=tot; ++i) ++ccnt[c[i].a&511];
		for(int i=1; i<512; ++i) ccnt[i]+=ccnt[i-1];
		for(int i=tot; i>=1; --i) d[ccnt[c[i].a&511]--]=c[i];
		memset(ccnt,0,sizeof(ccnt));
		for(int i=1; i<=tot; ++i) ++ccnt[d[i].a>>9];
		for(int i=1; i<512; ++i) ccnt[i]+=ccnt[i-1];
		for(int i=tot; i>=1; --i) c[ccnt[d[i].a>>9]--]=d[i];
	}
}
void get_ans()
{
	bit.clear();
	int cnt=0;
	for(int i=1; i<=tot; ++i)
	{
		if(c[i].op==1) bit.upd(c[i].b),++cnt;
		else ans+=(cnt-bit.get_sum(c[i].b-1))*nowf;
	}
}
void dfz(int u)
{
	vis[u]=1;
	bit.clear(),nowf=1,bitall=tot=0;
	for(int v:e[u]) if(!vis[v]) dfs1(v,u,1e9,0,0);
	for(int v:e[u]) if(!vis[v]) dfs2(v,u,u,u,0);
	sort(),get_ans();
	nowf=-1;
	for(int v:e[u])
	{
		if(vis[v]) continue;
		bit.clear(),bitall=tot=0;
		dfs1(v,u,1e9,0,0),dfs2(v,u,u,u,0);
	    sort(),get_ans();
	}
	bit.clear(),nowf=1,bitall=tot=0;
	for(int v:e[u]) if(!vis[v]) dfs1(v,u,1e9,0,1);
	for(int v:e[u]) if(!vis[v]) dfs2(v,u,u,u,1);
	sort(),get_ans();
	nowf=-1;
	for(int v:e[u])
	{
		if(vis[v]) continue;
		bit.clear(),bitall=tot=0;
		dfs1(v,u,1e9,0,1),dfs2(v,u,u,u,1);
	    sort(),get_ans();
	}
	dfs3(u,u,0,1e9,0);
	for(int v:e[u])
	{
		if(vis[v]) continue;
		allnode=siz[v],nowroot=0,get_root(v,u);
		dfz(nowroot);
	}
}
int cnt[200010];
int tag[200010];
vector<int> vec[200010];
int wz[200010];
void merge(int x,int y)
{
	if(vec[x].size()<vec[y].size())
	{
		for(int i:vec[x]) cnt[i]-=tag[x]-tag[y],vec[y].push_back(i),wz[i]=y;
	}
	else
	{
		for(int i:vec[y]) cnt[i]-=tag[y]-tag[x],vec[x].push_back(i),wz[i]=x;
	}
}
int fa[400010],len[400010];
int main()
{
	n=read();
	for(int i=1; i<=n-1; ++i)
	{
		int u=read(),v=read();
		e[u].push_back(v),e[v].push_back(u);
	}
	allnode=n,ax[nowroot=0]=1e9,get_root(1,0);
	dfz(nowroot);
	writel(ans),writec('\n');
	for(int i=1; i<=n; ++i) cnt[i]=n;
	for(int i=n; i>=1; --i)
	{
		vec[i].push_back(i),wz[i]=i;
		for(int j:e[i])
		{
			if(j>i) merge(wz[i],wz[j]);
		}
		++tag[wz[i]];
	}
	for(int i=1; i<=n; ++i) cnt[i]-=tag[wz[1]];
	for(int i=1; i<=n; ++i) fa[i]=i;
	m=read();
	int now=n;
	for(int i=1; i<=m; ++i)
	{
		int x=read();
		fa[++now]=fa[x],len[now]=len[x]+1;
		ans+=cnt[fa[now]]+i-len[now];
		writel(ans),writec('\n');
	}
	flush();
	return 0;
}