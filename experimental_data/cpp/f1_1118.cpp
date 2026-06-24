#include<cstdio>
using namespace std;
struct edge
{
	int from,to,next;
}e[600005];
int head[300005],cnt,col[300005];
int f1[300005],f2[300005],f[300005];
void add(int x,int y)
{
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].next=head[x];
	head[x]=cnt;
}
int ans;
void dfs(int now,int pre)
{
	if(col[now]==1)
		++f1[now];
	if(col[now]==2)
		++f2[now];
	for(int i=head[now];i;i=e[i].next)
	{
		if(e[i].to!=pre)
		{
			f[e[i].to]=now;
			dfs(e[i].to,now);
			f1[now]+=f1[e[i].to];
			f2[now]+=f2[e[i].to];	
		}
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&col[i]);
	for(int i=1;i<n;++i)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		add(a,b);
		add(b,a);
	}
	dfs(1,0);
	for(int i=1;i<=cnt;++i)
	{
		if(e[i].from==f[e[i].to])
			if((!f1[e[i].to]||!f2[e[i].to])&&(f1[1]==f1[e[i].to]||f2[1]==f2[e[i].to]))
				++ans;
	}
	printf("%d",ans);
	return 0;
}