//by yjz

#include<bits/stdc++.h>

using namespace std;

#define FF first

#define SS second

#define PB push_back 

#define MP make_pair

typedef long long ll;

const ll INF=1<<28;

const ll LINF=1ll<<61;

//My own input/output stream

#define geti(x) x=getnum()

#define getii(x,y) geti(x),geti(y)

#define getiii(x,y,z) getii(x,y),geti(z)

#define puti(x) putnum(x),putsp()

#define putii(x,y) puti(x),putnum(y),putsp()

#define putiii(x,y,z) putii(x,y),putnum(z),putsp()

#define putsi(x) putnum(x),putendl()

#define putsii(x,y) puti(x),putnum(y),putendl()

#define putsiii(x,y,z) putii(x,y),putnum(z),putendl()

inline ll getnum()

{

	register ll r=0;register bool ng=0;register char c;c=getchar();

	while(c!='-'&&(c<'0'||c>'9'))c=getchar();

	if(c=='-')ng=1,c=getchar();

	while(c!=' '&&c!='\n')r=r*10+c-'0',c=getchar();

	if(ng)r=-r;return r;

}

template <class T> inline void putnum(T x)

{

	if(x<0)putchar('-'),x=-x;

	register short a[20]={},sz=0;

	while(x>0)a[sz++]=x%10,x/=10;

	if(sz==0)putchar('0');

	for(int i=sz-1;i>=0;i--)putchar('0'+a[i]);

}

inline void putsp(){putchar(' ');}

inline void putendl(){putchar('\n');}

inline char mygetchar(){register char c=getchar();while(c==' '||c=='\n')c=getchar();return c;}

int head[11111],nxt[61111],to[61111],cap[61111],tot=1;

void add_edge(int x,int y,int c)

{

	nxt[++tot]=head[x];

	head[x]=tot;

	to[tot]=y;

	cap[tot]=c;

	nxt[++tot]=head[y];

	head[y]=tot;

	to[tot]=x;

	cap[tot]=0;

}

int lv[11111];

int que[11111];

void bfs(int x)

{

	memset(lv,-1,sizeof(lv));

	int qsz=0;

	que[qsz++]=x;

	lv[x]=0;

	for(int i=0;i<qsz;i++)

	{

		int u=que[i];

		for(int j=head[u];j;j=nxt[j])

		{

			if(cap[j]&&lv[to[j]]==-1)

			{

				que[qsz++]=to[j];

				lv[to[j]]=lv[u]+1;

			}

		}

	}

}

int it[11111];

int dfs(int x,int T,int f)

{

	if(x==T)return f;

	int tmp=f;

	for(int &i=it[x];i;i=nxt[i])

	{

		int u=to[i];

		if(lv[u]==lv[x]+1&&cap[i])

		{

			int d=dfs(u,T,min(f,cap[i]));

			if(d>0)

			{

				cap[i]-=d;

				cap[i^1]+=d;

				f-=d;

				if(!f)return tmp;

			}

		}

	}

	return tmp-f;

}

int max_flow(int S,int T)

{

	int ans=0;

	while(true)

	{

		bfs(S);

		if(lv[T]==-1)return ans;

		for(int i=0;i<=T;i++)it[i]=head[i];

		int tmp;

		while((tmp=dfs(S,T,23333333))>0)

		{

			ans+=tmp;

		}

	}

}

int n,q,b;

int sum[10111];

int main()

{

	getiii(n,b,q);

	memset(sum,-1,sizeof(sum));

	sum[0]=0;

	sum[b]=n;

	for(int i=1;i<=q;i++)

	{

		int x,y;

		getii(x,y);

		if(sum[x]!=-1&&sum[x]!=y)

		{

			puts("unfair");

			return 0;

		}

		sum[x]=y;

	}

	int tn=5,S=q+7,T=q+8;

	for(int i=1;i<=5;i++)add_edge(i,T,n/5);

	int pre=0;

	for(int i=1;i<=b;i++)

	{

		if(sum[i]==-1)continue;

		else

		{

			tn++;

			if(sum[i]-sum[pre]<0)

			{

				puts("unfair");

				return 0;

			}

			add_edge(S,tn,sum[i]-sum[pre]);

			int cnt[6]={};

			for(int j=pre+1;j<=i;j++)

			{

				cnt[j%5+1]++;

			}

			for(int j=1;j<=5;j++)

			{

				if(cnt[j]>0)add_edge(tn,j,cnt[j]);

			}

			pre=i;

		}

	}

	if(max_flow(S,T)==n)puts("fair");else puts("unfair");

	return 0;

}