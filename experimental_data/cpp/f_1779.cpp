// LUOGU_RID: 100611114
#include <bits/stdc++.h>

using namespace std;

inline int read()

{

	int s=0,f=1;

	char c=getchar();

	while(c<'0'||c>'9')

	{

		if(c=='-')

		f=-1;

		c=getchar(); 

	}

	while(c>='0'&&c<='9')

	{

		s=s*10+c-'0';

		c=getchar();

	}

	return s*f;

}

int n;

int num[300007];

vector <int> a[300007];

int sub[300007],sum[300007];

bool pd[300007][38],dp[300007][38];

bool f[38];

void dfs(int x,int fa)

{

	sub[x]=1;

	sum[x]=num[x];

	for(int i=0;i<a[x].size();++i)

	{

		int v=a[x][i];

		if(v==fa)

		continue;

		dfs(v,x);

		sum[x]^=sum[v];

		sub[x]+=sub[v];

	}

}

void dfs2(int x,int fa)

{

	pd[x][num[x]]=1;

	for(int i=0;i<a[x].size();++i)

	{

		int v=a[x][i];

		if(v==fa)

		continue;

		dfs2(v,x);

		for(int j=0;j<32;++j)

		{

			dp[v][j]=f[j]=pd[x][j];

	//		cout<<x<<" "<<v<<" "<<j<<" "<<dp[v][j]<<endl;

			pd[x][j]=0;

		}

		for(int j=0;j<32;++j)

		{

			for(int k=0;k<32;++k)

			{

				if(f[j]&&pd[v][k])

				pd[x][j^k]|=1;

			}

		}

	}

	pd[x][sum[x]]|=1;

	if(!(sub[x]&1))

	pd[x][0]|=1;

}

int v[1000007],top;

void dfs3(int x,int fa,int k)

{

	if(k==sum[x])

	return;

	if((!(sub[x]&1))&&k==0)

	{

		v[++top]=x;

		v[++top]=x;

		return;

	}

	for(int i=a[x].size()-1;i>=0;--i)

	{

		int v=a[x][i];

		if(v==fa)

		continue;

		for(int j=0;j<32;++j)

		{

			if(pd[v][j]&&dp[v][k^j])

			{

				dfs3(v,x,j);

				k^=j;

				break;

			}

		}

	}

}

int main()

{

	n=read();

	for(int i=1;i<=n;++i)

	num[i]=read();

	for(int i=2;i<=n;++i)

	{

		int faa=read();

		a[faa].push_back(i);

		a[i].push_back(faa);

	}

	dfs(1,0);

	dfs2(1,0);

	if(pd[1][0])

	{

		dfs3(1,0,0);

		if(top<2*n)

		v[++top]=1;

		printf("%d\n",top);

		for(int i=1;i<=top;++i)

		printf("%d ",v[i]);

	}

	else

	puts("-1");

	return 0;

}