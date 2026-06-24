#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
#define ll long long
const ll M=1000000009ll;
const int N=100008;
ll n,m,a,b,ra,w;
ll suan(ll x,ll y)
{
	ll t=1;while(y){if(y&1)t=t*x%M;x=x*x%M;y>>=1;}return t;
}
char c[N];
struct aa{ll a[2][2];}ori,one,d;
void cf(aa &a,aa &b,aa &c)
{
	memset(d.a,0,sizeof(d.a));
	ll i,j,k;
	for(i=0;i<=1;i++)
	for(j=0;j<=1;j++)
	for(k=0;k<=1;k++)d.a[i][j]=(d.a[i][j]+a.a[i][k]*b.a[k][j])%M;
	for(i=0;i<=1;i++)
	for(j=0;j<=1;j++)c.a[i][j]=d.a[i][j];
	return;
}
int main(void)
{
	std::ios::sync_with_stdio(false);
	cin>>n>>a>>b>>m>>c;
	ll i,k,s;
	ra=suan(a,M-2);
	k=suan(a,n);w=ra*b%M;
	s=0;
	for(i=0;i<m;i++)
	{
		s+=(c[i]=='+'?1:(-1))*k;
		k=k*w%M;
	}
	w=(suan(ra,m)*suan(b,m)%M+M)%M;
	k=s=(s%M+M)%M;
	n=(n+1)/m;
	memset(one.a,0,sizeof(one.a));
	memset(ori.a,0,sizeof(ori.a));
	one.a[0][0]=one.a[1][1]=1;
	ori.a[0][0]=ori.a[0][1]=1;ori.a[1][1]=w;
	while(n){if(n&1)cf(one,ori,one);cf(ori,ori,ori);n>>=1;}
	k=(one.a[0][1]*k%M+M)%M;
	cout<<k;
	return 0;
}