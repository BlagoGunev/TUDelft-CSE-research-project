#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define ll long long
#define mp(x,y) make_pair(x,y)
#define N 1000005
using namespace std;
int read()
{
	int p=0;char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9')p=p*10+c-'0',c=getchar();
	return p;
}
int head[N],ver[N*2],nxt[N*2],tot;
void add(int a,int b)
{
	tot++;nxt[tot]=head[a];head[a]=tot;ver[tot]=b;return ;
}
int f[N],size[N],d[N];
int find(int x)
{
	if(x==f[x])return x;
	return f[x]=find(f[x]);
}
int ds[N];
int mx,id;
void dfs(int x,int fa,int dis)
{
	ds[x]=max(ds[x],dis);
	if(dis>mx)
	{
		mx=dis;
		id=x;
	}
	for(int i=head[x];i;i=nxt[i])
	{
		if(ver[i]==fa)continue;
		dfs(ver[i],x,dis+1);
	}
}
vector<int>v[N];
vector<pair<int,int> >q[N];
int n,m,qq;
double ans[N];
int num[N];
ll sum[N];
void solve(int x)
{
	int sz=size[x];
	for(int i=0;i<=sz;i++)num[i]=sum[i]=0;
	for(int i=0;i<v[x].size();i++)num[v[x][i]]++,sum[v[x][i]]+=v[x][i];
	for(int i=0;i<=sz;i++)num[i]+=num[i-1],sum[i]+=sum[i-1];
	ll sm=sum[sz];
	int pre=0;double las;
	for(int i=0;i<q[x].size();i++)
	{
		int p=q[x][i].first,id=q[x][i].second;
		if(p==x)
		{
			ans[id]=-1;
			continue;
		}
		if(p==pre)
		{
			ans[id]=las;
			continue;
		}
		pre=p;ll cnt=0,as=0;int tmp=max(d[x],d[p]);
		for(int j=0;j<v[p].size();j++)
		{
			int now=tmp-v[p][j]-1;
			if(now<0)
			{
				as+=1LL*(v[p][j]+1)*sz;
				as+=sm;
			}
			else
			{
				cnt+=num[now];
				as+=1LL*(v[p][j]+1)*(sz-num[now]);
				as+=sm-sum[now];
			}
		}
		ans[id]=las=((double)(as+cnt*tmp))/(1LL*sz*size[p]);
	}
}
int main()
{
	scanf("%d%d%d",&n,&m,&qq);
	int t1,t2;
	for(int i=1;i<=n;i++)f[i]=i,size[i]=1;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&t1,&t2);
		add(t1,t2);add(t2,t1);
		int aa=find(t1),bb=find(t2);
		f[aa]=bb;size[bb]+=size[aa];
	}
	for(int i=1;i<=n;i++)
	{
		if(find(i)==i)
		{
			mx=-1;id=0;
			dfs(i,-1,0);
			mx=-1;
			dfs(id,-1,0);
			d[i]=mx;
			dfs(id,-1,0);
		}
	}
//	cout<<ds[1]<<' '<<ds[2]<<' '<<ds[3]<<endl;
	for(int i=1;i<=n;i++)
	{
		v[find(i)].push_back(ds[i]);
	}
	for(int i=1;i<=qq;i++)
	{
		scanf("%d%d",&t1,&t2);
		t1=find(t1);t2=find(t2);
		if(size[t1]>size[t2])swap(t1,t2);
		q[t2].push_back(mp(t1,i));
	}
	for(int i=1;i<=n;i++)
	{
		if(find(i)==i)
		{
			sort(v[i].begin(),v[i].end());
			sort(q[i].begin(),q[i].end());
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(find(i)==i)
		{
			solve(i);
		}
	}
	for(int i=1;i<=qq;i++)
	{
		printf("%.10lf\n",ans[i]);
	}
	return 0;
}