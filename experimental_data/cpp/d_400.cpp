#include<bits/stdc++.h>

using namespace std;

#define pc putchar_unlocked

#define gc getchar_unlocked

typedef long long ll;

typedef unsigned long long llu;

#define mp make_pair

#define pb push_back

#define sc(x) scanf("%d",&x)

#define sc2(x,y) scanf("%d%d",&x,&y)

#define sc3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define scl(x) scanf("%lld",&x)

#define scl2(x,y) scanf("%lld%lld",&x,&y)

#define scl3(x,y,z) scanf("%lld%lld%lld",&x,&y,&z)

#define scstr(x) scanf("%s",x)

#define pd(x) printf("%d",x)

#define pstr(x) printf("%s",x)

#define newl() printf("\n")

#define fl(i,n) for (i=0;i<n;i++)

#define fle(i,n) for (i=1;i<=n;i++)

#define fla(i,a,n) for (i=a;i<n;i++)

#define mem(a,i) memset(a,i,sizeof(a))

#define fi first

#define se second

typedef pair<int,int> pii;

typedef pair<int,pair<int,int> > piii ;

typedef pair<ll,ll> pll;

typedef pair<ll,int> pli;

#define gcd __gcd

#define wl(n) while (n--)

#define debug(x) cout<<"debug->"<<#x<<"::"<<x<<endl

#define debug2(x,y) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\n"

#define debug3(x,y,z) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<"\n"

#define tr(container, it)  for(typeof(container.begin()) it = container.begin(); it != container.end(); it++) 

#define all(v) v.begin(),v.end()

const double eps=0.000000000000001 ;

#define MOD 1000000007

typedef long double LF;

typedef double lF;

//-------------

#define inf 10000000

int n,m,k;

int c[510],sc[510];

int par[100010];

vector<pii>gr[100010];

void reset()

{

	int i,j;

	for (i=1;i<=n;i++)

		par[i]=i;

}

int fin(int x)

{

	if (par[x]!=x)

		par[x]=fin(par[x]);

	return par[x];

}

int un(int x,int y)

{

	int xr=fin(x),yr=fin(y);

	if (xr!=yr)

	{

		par[xr]=yr;

		return 1;

	}

	return 0;

}

int d[510][510];

void mak()

{

	int i,j;

	for (i=1;i<=k;i++)

		for (j=1;j<=k;j++)

			d[i][j]=inf;

	for (i=1;i<=k;i++)

		d[i][i]=0;

	for (i=1;i<=n;i++)

	{

		int z=gr[i].size();

		for (j=0;j<z;j++)

		{

			int v=lower_bound(c+1,c+k+1,gr[i][j].fi)-c,w=gr[i][j].se;

			int x=lower_bound(c+1,c+k+1,i)-c;

			d[x][v]=min(d[x][v],w);

		}

	}

	int z;

	for (z=1;z<=k;z++)

		for (i=1;i<=k;i++)

			for (j=1;j<=k;j++)

			{

				if (d[i][j]>d[i][z]+d[z][j])

					d[i][j]=d[i][z]+d[z][j];

			}



}

int main()

{	



	sc3(n,m,k);

	int i,j;

	for (i=1;i<=k;i++)

		sc(c[i]);

	for (i=1;i<=k;i++)

	{

		c[i]=c[i-1]+c[i];

	}

	for (i=1;i<=k;i++)

		sc[i]=c[i-1]+1;

	reset();

	for (i=0;i<m;i++)

	{

		int x,y,w;

		sc3(x,y,w);

		gr[x].pb(mp(y,w));

		gr[y].pb(mp(x,w));

		if (w==0)

		{

			un(x,y);

		}

	}

	int f=1;

	for (i=1;i<=k;i++)

	{



		for (j=sc[i]+1;j<=c[i];j++)

		{

			//printf("for :%d , root is :%d,%d\n",j,fin(j),fin(j-1));

			if (fin(j)!=fin(j-1))

			{

				f=0;

				break;

			}

		}

		if (!f)break;

	}

	if (!f)

	{

		printf("No\n");

		return 0;

	}

	mak();

	printf("Yes\n");

	for (i=1;i<=k;i++)

	{



		for (j=1;j<=k;j++)

		{	

			printf("%d ",(d[i][j]>=inf?-1:d[i][j]));

		}

		printf("\n");

	}





	return 0;



}