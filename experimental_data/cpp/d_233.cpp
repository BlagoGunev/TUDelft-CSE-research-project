#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define mod 1000000007

int n,k;
long long m;
int c[110],cc[110][2];
long long tim[110];
long long f[110][10100];

int sqr(long long x){return (x*x)%mod;}

int qming(long long a,long long b)
{
	if (!b)	return 1;
	if (b&1)	return (sqr(qming(a,b/2))*a)%mod;
	return sqr(qming(a,b/2));
}

void init()
{
	c[0]=1;
	for (int i=1;i<=n;i++)	
	{
		long long temp=c[i-1];
		temp*=(n-i+1);
		temp%=mod;
		temp*=qming(i,mod-2);
		temp%=mod;
		c[i]=temp;
	}	
}

int main()
{
	cin>>n>>m>>k;
	init();
	for (int i=0;i<n;i++)	if (m%n>i)	tim[i]=1;else tim[i]=0;
	for (int i=0;i<=n;i++)	cc[i][0]=qming(c[i],m/n),cc[i][1]=qming(c[i],m/n+1);
	f[0][0]=1;
	int a,b;
	for (int i=0;i<n;i++)
	{
		a=max(0,k-(n-i)*n);
		b=min(k,n*i);
		for (int j=a;j<=b;j++)
			for (int t=0;t<=n;t++)
			{
				if (j+t>k)	break;
				f[i+1][j+t]+=f[i][j]*cc[t][tim[i]];
				f[i+1][j+t]%=mod;
			}
	}
	cout<<f[n][k]<<endl;
	return 0;
}