#include<bits/stdc++.h>

using namespace std;

long long a,b,d[100001],f[100001],t[1001][1001],q,w,e,op,ld[1001][1001],v[1001][1001],mod=1e9+7,g[100001],u[1001][1006],pw1[1001][1001],pw[1001][1001],lim=1001;

long long pow_(long long qq,long long ww){long long ee=1;while(ww){if(ww&1) ee*=qq,ee%=1000000007;qq*=qq,qq%=1000000007,ww>>=1;}return ee%1000000007;}

void work(long long qq)

{

	for(int i=qq-1;i>=1;i--)

	{

		long long tt=0;

		for(int j=i+1;j<=qq;j++) tt+=ld[qq][j]*t[i][j],tt%=1000000007;

		ld[qq][i]=tt*pow_(qq-i,1000000007-2)%1000000007;

	}

}

void work1()

{

	for(int i=1;i<=a;i++) for(int j=1;j<i;j++) for(int k=1;k<=j;k++) v[i][k]-=v[j][k]*ld[i][j],v[i][k]%=1000000007;

}

void change(long long qq,long long ww,long long ee){for(int i=ww;i<=lim;i+=(i&(-i))) u[qq][i]+=ee,u[qq][i]%=1000000007;}

long long query(long long qq,long long ww){ww++;long long ann=0;for(int i=ww;i;i-=(i&(-i))) ann+=u[qq][i],ann%=1000000007;return ann;}

void build()

{

	for(int i=1;i<=a;i++) for(int j=1;j<=lim;j++) u[i][j]=0;for(int i=1;i<=a;i++) g[i]=1e12;

	for(int i=1;i<=a;i++) if(d[i]>0) g[i]=0;

	for(int i=a;i>=1;i--) for(int j=i+1;j<=a;j++) if(t[i][j]) g[i]=min(g[i],g[j]+1);

	for(int i=1;i<=a;i++)

	{

		for(int j=i;j<=a;j++) if(g[j]!=1e12) u[i][g[j]+1]+=pw1[i][g[j]]*v[j][i]%1000000007*d[j]%1000000007,u[i][g[j]+1]%=1000000007;

		for(int j=1;j<=lim;j++) u[i][j]+=u[i][j-1],u[i][j]%=1000000007;

		for(int j=lim;j>=2;j--) u[i][j]-=u[i][j-(j&(-j))],u[i][j]%=1000000007;

	}

}

void update(long long qq,long long ww)

{

	d[qq]+=ww;if(g[qq]==1e12) return;

	for(int i=1;i<=qq;i++) change(i,g[qq]+1,ww*pw1[i][g[qq]]%1000000007*v[qq][i]%1000000007);

}

long long qry(long long qq,long long ww,long long ee)

{

	long long ann=0;

	for(int i=ww;i<=ee;i++) if(g[i]>qq) ann+=d[i],ann%=1000000007;

	for(int i=1;i<=a;i++) ann+=query(i,qq)*pw[i][qq]%1000000007*(ld[i][ee]-ld[i][ww-1]),ann%=1000000007;

	return ann;

}

int main()

{

	for(int i=1;i<=1000;i++) for(int j=0;j<=1000;j++) pw[i][j]=pow_(i,j),pw1[i][j]=pow_(pw[i][j],1000000007-2);

	scanf("%lld",&a);for(int i=1;i<=a;i++) scanf("%lld",&d[i]);

	for(int i=1;i<=a;i++)

	{

		scanf("%lld",&q);t[i][i]=i;ld[i][i]=v[i][i]=1;

		for(int j=1;j<=q;j++) scanf("%lld",&w),t[i][w]=w;

	}for(int i=1;i<=a;i++) work(i);work1();

	for(int i=1;i<=a;i++) for(int j=1;j<=a;j++) ld[i][j]+=ld[i][j-1],ld[i][j]%=1000000007;

	for(int i=1;i<=a;i++) for(int j=1;j<=a;j++) v[i][j]=(v[i][j]+1000000007)%1000000007;

	scanf("%lld",&b);build();

	for(int i=1;i<=b;i++)

	{

		scanf("%lld%lld%lld",&op,&q,&w);

		if(op==1) scanf("%lld",&e),printf("%lld\n",(qry(q,w,e)%1000000007+1000000007)%1000000007);

		else

		{

			if(d[q]<=0&&d[q]+w>0) d[q]+=w,build();

			else update(q,w);

		}

	}

	return 0;

}