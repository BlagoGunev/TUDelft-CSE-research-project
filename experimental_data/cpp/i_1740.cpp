#include<iostream>

#include<cstdio>

#include<vector>

#define N 12000000

#define inf 1e9

using namespace std;

int read()

{

    char c=0;

    int sum=0;

    while (c<'0'||c>'9') c=getchar();

    while ('0'<=c&&c<='9') sum=sum*10+c-'0',c=getchar();

    return sum;

}

struct reads

{

    int st,d;

    bool operator != (const reads &t)const

    {

	return st!=t.st||d!=t.d;

    }

};

reads ds[N+1];

reads operator + (reads a,reads b)

{

    return (reads){a.st+b.st,a.d+b.d};

}

reads rst,zero;

int n,m,k,ta,tb,a[N+1],b[N+1],dp[N+1],dsp[N+1],DP[N+1],dque[N+1],l,r,res,ans=inf,tong[N+1],length;

bool used[N+1],vis[N+1];

int main()

{

    int x,l,r,lst;

    n=read(),m=read(),k=read();

    for (int i=0;i<m;++i) dp[i]=inf;

    dp[0]=0;

    for (int i=0;i<n;++i) a[i]=read();

    for (int i=0;i<n;++i) b[i]=(a[i]-a[(i+n-1)%n]+m)%m;

    for (int i=0;i<n;++i)

	if (!used[i])

	{

	    for (int j=0;j<m;++j) ds[j]=zero,dsp[j]=inf;

	    x=i,length=0,tong[++length]=b[x],used[x]=1,res=0;

	    while (!used[(x+k)%n])

	    {

		x+=k;

		if (x>=n) x-=n,vis[length]=1;

		else vis[length]=0;

		tong[++length]=b[x],used[x]=1;

	    }

	    if (x+k>=n) x-=n,vis[length]=1;

	    for (int j=0;j<m;++j) ds[j]=zero,dsp[j]=inf;

	    for (int j=1;j<=length;++j)

	    {

		res=(res+tong[j])%m,l=(m-res)%m,r=(m+((m-1)>>1)-res)%m;

		if (vis[j])

		{

		    if (!i) ta++;

		    tb=(tb+res)%m;

		}

		ds[l]=ds[l]+(reads){-l,1},ds[r+1]=ds[r+1]+(reads){-(((m-1)>>1)+1)+(r+1),-1};

		if (l>r) ds[0]=ds[0]+(reads){m-l,1};

		l=(m+((m-1)>>1)+1-res)%m,r=(m-1-res)%m;

		ds[l]=ds[l]+(reads){m-((m-1)>>1)-1+l,-1},ds[r+1]=ds[r+1]+(reads){-(r+1),1};

		if (l>r) ds[0]=ds[0]+(reads){l-((m-1)>>1)-1,-1};

	    }

	    if (res)

	    {

		puts("-1");

		return 0;

	    }

	    lst=-1,rst=zero;

	    for (int j=0;j<m;++j)

	    {

		rst=rst+ds[j];

		if (j==m-1||ds[j+1]!=zero)

		{

		    for (int k=0;k<m;++k) DP[(k+lst+1)%m]=dp[k]+rst.st+(lst+1)*rst.d;

		    for (int k=0;k<m;++k) DP[k+m]=DP[k];

		    l=1,r=0;

		    for (int k=0;k<(m<<1);++k)

		    {

			while (l<=r&&k-dque[l]>j-lst) l++;

			while (l<=r&&DP[dque[r]]-dque[r]*rst.d>=DP[k]-k*rst.d) r--;

			dque[++r]=k;

			if (k>=m&&l<=r) dsp[k-m]=min(dsp[k-m],DP[dque[l]]+(k-dque[l])*rst.d);

		    }

		    lst=j;

		}

	    }

	    for (int j=0;j<m;++j) dp[j]=dsp[j];

	}

    for (int i=0;i<m;++i)

	if ((ta*i+tb)%m==a[n-1])

	    ans=min(ans,dp[i]);

    printf("%d\n",(ans==inf)?-1:ans);

    return 0;

}