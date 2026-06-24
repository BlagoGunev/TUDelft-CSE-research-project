#include<cstdio>
#include<cstring>
#include<algorithm>
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0'||ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch<='9'&&ch>='0')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	x=f?-x:x;
	return;
}
const int maxn=1e5+7;
struct node
{
	int v,next;
}e[maxn];
int cnt,head[maxn],n,fa[maxn],s[maxn],a[maxn];
void ins(int u,int v){e[++cnt].v=v;e[cnt].next=head[u];head[u]=cnt;}
void dfs(int x,int sum)
{
	if(s[x]<=-1)
	{
		int mn=2147483647;
		for(int p=head[x];p;p=e[p].next)
		{
			int v=e[p].v;
			mn=std::min(mn,s[v]);
		}
		if(mn==2147483647)return;
		mn-=sum;
		a[x]=mn;sum+=a[x];
		for(int p=head[x];p;p=e[p].next)
			s[e[p].v]-=sum;
		for(int p=head[x];p;p=e[p].next)
			dfs(e[p].v,sum);
		return;
	}
	a[x]=s[x];
	for(int p=head[x];p;p=e[p].next)
	{
		int v=e[p].v;
		dfs(v,sum+a[x]);
	}
}
int main()
{
//	freopen("in","r",stdin);
	read(n);
	for(int i=2;i<=n;i++)
	{
		int x;read(x);
		ins(x,i);fa[i]=x;
	}
	for(int i=1;i<=n;i++)
	{
		read(s[i]);
		if(s[i]!=-1&&s[i]<s[1])
		{
			printf("-1\n");
			return 0;
		}
	}
	dfs(1,0);
	long long ans=0;
	for(int i=1;i<=n;i++)
	if(a[i]<0)
	{
		printf("-1\n");
		return 0;
	}
	else ans+=a[i];
	printf("%I64d\n",ans);
	return 0;
}