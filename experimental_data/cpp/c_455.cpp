#include <iostream>

#include <cstdio>

#include <cstring>

#include <cmath>

#include <algorithm>

#include <vector>

#include <map>

#define N 300005

#define INF 1000000001

using namespace std;

typedef long long ll;

int read()

{

    int x=0,f=1;char ch=getchar();

    while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}

    while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}

    return x*f;

}



int n,m,k,root,T,ans;

int father[N];

vector<int>v[N];

int dis[N];



int findf(int x){

	return father[x]==x?x:father[x]=findf(father[x]);

} 



void dfs(int x,int fa,int deep)

{

	father[x]=root;

	if(deep>ans)

	{

		ans=deep;

		T=x;

	}

	for(int i=0;i<v[x].size();i++)

		if(v[x][i]!=fa) dfs(v[x][i],x,deep+1);

}



void mergef(int x,int y)

{

	static int fx,fy;

	fx=findf(x),fy=findf(y);

	if(fx==fy) return;

	if(dis[fx]<dis[fy]) swap(dis[fx],dis[fy]);

	father[fy]=fx;

	dis[fx]=max(dis[fx],(dis[fx]+1)/2+(dis[fy]+1)/2+1);

}



int main()

{

    n=read(),m=read(),k=read();

    for(int i=1;i<=n;i++) father[i]=i;

    for(int i=1;i<=m;i++)

    {

    	static int x,y;

    	x=read(),y=read();

    	v[x].push_back(y);

    	v[y].push_back(x);

	}

	for(int i=1;i<=n;i++)

	{

		if(father[i]==i)

		{

			ans=-1;

			root=T=i;

			dfs(i,0,0);

			ans=-1;

			dfs(T,0,0);

			dis[i]=ans;

		}

	}

	while(k--)

	{

		static int f,x,y;

		f=read();

		if(f&1)

		{

			x=read();

			int fx=findf(x);

			printf("%d\n",dis[fx]);

		}

		else 

		{

			x=read(),y=read();

			mergef(x,y);

		}

	}

    return 0;

}