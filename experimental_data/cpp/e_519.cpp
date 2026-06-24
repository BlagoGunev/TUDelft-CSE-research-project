#include <cstdio>

#include <queue>

#include <vector>

#include <algorithm>

#include <cstdlib>

#include <cstring>

#include <map>

#include <stack>

#define N 100005

using namespace std;



void read(int &k)

{

	int x=0,f=1;char ch=getchar();

	while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}

	while(ch>='0'&&ch<='9') {x=x*10+ch-'0';ch=getchar();}

	k=x*f;

}



int n,nn,m;

int p[N],deep[N],fa[N][23],dis[N][23],size[N];

struct edge

{

	int b,nt,w;

}e[N*2];



void anode(int x,int y,int w)

{

	nn++;e[nn].b=y;e[nn].nt=p[x];p[x]=nn;e[nn].w=w;

	nn++;e[nn].b=x;e[nn].nt=p[y];p[y]=nn;e[nn].w=w;

}



void dfs(int x)

{

	for(int i=1;(1<<i)<=deep[x];i++)

	{

		fa[x][i]=fa[fa[x][i-1]][i-1];

		dis[x][i]=dis[fa[x][i-1]][i-1]+dis[x][i-1];

	}

	size[x]=1;

	for(int i=p[x];i;i=e[i].nt)

	{

		int v=e[i].b;

		if(!deep[v])

		{

			deep[v]=deep[x]+1;

			fa[v][0]=x;

			dis[v][0]=1;

			dfs(v);

			size[x]+=size[v];

		}

	}

}



int lca(int x,int y)

{

	if(x==y) return x;

	if(deep[x]<deep[y]) swap(x,y);

	int t=deep[x]-deep[y];

	for(int i=20;i>=0;i--)

		if(t&(1<<i))

			x=fa[x][i];

	if(x==y) return x;

	for(int i=20;i>=0;i--)

		if(fa[x][i]!=fa[y][i])

			x=fa[x][i],y=fa[y][i];

	return fa[x][0];

}



int query(int x,int y)

{

	int rnt=0;

	if(deep[x]<deep[y]) swap(x,y);

	int t=deep[x]-deep[y];

	for(int i=20;i>=0;i--)

		if(t&(1<<i))

		{

			rnt+=dis[x][i];

			x=fa[x][i];

		}

	return rnt;

}



int shift_root(int x,int t)

{

	for(int i=20;i>=0;i--)

		if(t&(1<<i))

			x=fa[x][i];

	return x;

}



int main()

{

	//freopen("D:\\code\\in.txt","r",stdin);

	//freopen("election.in","r",stdin);

	//freopen("election.out","w",stdout);

	read(n);

	for(int x,y,i=1;i<n;i++)

	{

		read(x),read(y);

		anode(x,y,1);

	}

	deep[1]=1;

	dfs(1);	

//	for(int i=1;i<=n;i++)printf("%d\n",deep[i]);

	read(m);

	while(m--)

	{

		int x,y;

		read(x),read(y);

		if(x==y)

		{

			printf("%d\n",n);

			continue;

		}

		int llca=lca(x,y);

		int dist=query(llca,x)+query(llca,y);

		//printf("%d\n",dist);

		int ans=0;

		if(dist%2==1) printf("0\n");

		else 

		{

			if(deep[x]==deep[y])

			{

				int tmpx=shift_root(x,dist/2-1);

				int tmpy=shift_root(y,dist/2-1);

				ans=n-size[tmpx]-size[tmpy];

			}	

			else if(deep[x]>deep[y])

			{

				int tmpx=shift_root(x,dist/2-1);

				ans=size[fa[tmpx][0]]-size[tmpx];

			}

			else if(deep[x]<deep[y])

			{

				int tmpy=shift_root(y,dist/2-1);

				ans=size[fa[tmpy][0]]-size[tmpy];

			}

			printf("%d\n",ans);

		} 

	}

	return 0;

}