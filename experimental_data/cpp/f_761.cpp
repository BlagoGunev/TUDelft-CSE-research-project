#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

const int N=1005,M=300005,T=4105;

typedef long long LL;

int n,m,k,t[26][T],A[M],B[M],C[M],D[M],cnt[N];

LL ans,p[N][N],s[26][N][N];

char c,typ[M],map[N][N];

vector <int> In[N],Out[N];

int read()
{
	for (c=getchar();c<'0' || c>'9';c=getchar());
	int x=c-48;
	for (c=getchar();c>='0' && c<='9';c=getchar()) x=x*10+c-48;
	return x;
}

void insert(int l,int r,int a,int b,int *t,int v,int x)
{
	if (l==a && r==b)
	{
		t[x]+=v; return;
	}
	int mid=l+r>>1;
	if (b<=mid) insert(l,mid,a,b,t,v,x<<1);
	else if (a>mid) insert(mid+1,r,a,b,t,v,x<<1|1);
	else
	{
		insert(l,mid,a,mid,t,v,x<<1); insert(mid+1,r,mid+1,b,t,v,x<<1|1);
	}
}

int query(int l,int r,int *t,int v,int x)
{
	if (l==r) return t[x];
	int mid=l+r>>1;
	if (v<=mid) return query(l,mid,t,v,x<<1)+t[x];else return 
	query(mid+1,r,t,v,x<<1|1)+t[x];
}

int main()
{
	n=read(); m=read(); k=read();
	for (int i=1;i<=n;i++) scanf("%s",map[i]+1);
	for (int i=1;i<=k;i++)
	{
		A[i]=read(); B[i]=read(); C[i]=read(); D[i]=read();
		In[A[i]].push_back(i); Out[C[i]].push_back(i);
		for (c=getchar();c<'a' || c>'z';c=getchar()); typ[i]=c-'a';
	}
	for (int i=1;i<=n;i++)
	{
		vector <int> ::iterator it;
		for (it=In[i].begin();it!=In[i].end();it++)
		{
			insert(1,m,B[*it],D[*it],t[typ[*it]],1,1);
		}
		
		for (int j=1;j<=m;j++)
		{
			int sum=0,ss=0;
			for (int x=0;x<26;x++)
			{
				cnt[x]=query(1,m,t[x],j,1);
				ss+=cnt[x];
				sum+=cnt[x]*x;
			}
			cnt[map[i][j]-'a']+=k-ss;
			sum+=(k-ss)*(map[i][j]-'a');
			for (int x=0;x<26;x++)
			{
				if (x==map[i][j]-'a')
				p[i][j]=p[i-1][j]+p[i][j-1]-p[i-1][j-1]+sum;
				s[x][i][j]=s[x][i-1][j]+s[x][i][j-1]-s[x][i-1][j-1]+sum;
				if (x>0) cnt[x]+=cnt[x-1];
				sum+=cnt[x]-(k-cnt[x]);
			}
		}
		
		for (it=Out[i].begin();it!=Out[i].end();it++)
		{
			insert(1,m,B[*it],D[*it],t[typ[*it]],-1,1);
		}
	}
	ans=1e16;
	for (int i=1;i<=k;i++)
	{
		ans=min(ans,p[n][m]-(p[C[i]][D[i]]-p[A[i]-1][D[i]]-p[C[i]][B[i]-1]+p[A[i]-1][B[i]-1])
		+(s[typ[i]][C[i]][D[i]]-s[typ[i]][A[i]-1][D[i]]-s[typ[i]][C[i]][B[i]-1]+s[typ[i]][A[i]-1][B[i]-1]));
	}
	printf("%I64d\n",ans);
	return 0;
}