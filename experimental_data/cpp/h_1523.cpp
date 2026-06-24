#include<cstdio>

#define max(a,b) (a>b?a:b)

int n,q,m,a[60001];

int t[20][35][20001],c[20][35][20001],f[100];

int v[60001],vp[60001];

struct node{

	int x,y,k,ans;

}b[60001];

int pl[60001][31];

int find(const int x2,const int l,const int r)

{

	return max(c[v[r-l+1]][x2][l],c[v[r-l+1]][x2][r-vp[r-l+1]+1]);

}

void make(const int j)

{

	for(int i=1;i<=n;++i)

		for(int k=0;k<=30;++k)

			c[0][k][i]=t[j][k][i];

	for(int l=1;l<17;++l)

		for(int i=1;i<=n;++i)

		{

			int nxt=i+(1<<l-1);

			if(nxt>n)nxt=n;

			for(int k=0;k<=30;++k)

				c[l][k][i]=max(c[l-1][k][i],c[l-1][k][nxt]);

		}

}

int main()

{

	scanf("%d%d",&n,&q);

	m=n+2;while(m!=(m&-m))m+=m&-m;

	v[0]=-1;

	for(int i=1;i<=n;++i)

	{

		scanf("%d",a+i);

		for(int k=0;k<=30;++k)t[0][k][i]=i+a[i]+k;

		v[i]=v[i>>1]+1;

		vp[i]=1<<v[i];

	}

	for(int i=1;i<=q;++i)

	{

		scanf("%d%d%d",&b[i].x,&b[i].y,&b[i].k);

		for(int j=0;j<=b[i].k;++j)pl[i][j]=b[i].x;

	}

	for(int j=1;j<17;++j)

	{

		make(j-1);

		for(int i=1;i<=n;++i)

		{

			for(int k=0;k<=30;++k)

				f[k]=find(k,i,i);

			for(int k1=0;k1<=30;++k1)

			{

				int mx=0;

				for(int k2=0;k2<=k1;++k2)

				{

					int l=find(k2,i,f[k1-k2]);

					mx=max(mx,l);

				}

				t[j][k1][i]=mx;

			}

		}

	}

	for(int j=16;~j;--j)

	{

		make(j);

		for(int id=1;id<=q;++id)

		{

			for(int k=0;k<=b[id].k;++k)

				if(find(b[id].k-k,b[id].x,pl[id][k])>=b[id].y)

					goto out;

			b[id].ans|=1<<j;

			for(int k1=b[id].k;~k1;--k1)

				for(int k2=b[id].k-k1;~k2;--k2)

				{

					int p=find(k2,b[id].x,pl[id][k1]);

					pl[id][k1+k2]=max(pl[id][k1+k2],p);

				}

			out:;

		}

	}

	for(int i=1;i<=q;++i)

		if(b[i].x==b[i].y)puts("0");

		else printf("%d\n",b[i].ans+1);

}