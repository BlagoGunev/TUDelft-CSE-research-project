#include <bits/stdc++.h>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
const int INF = 1000000005;
typedef int64_t ll;
const int N = 100005;
int a[N],n;
ll k;
ll sum[N],v[N];
int c[N],b[N],f[N];
bool cmp(int x,int y)
{
	return sum[x]<sum[y];
}
int lowbit(int x)
{
	return x&(-x);
}
int getsum(int x)
{
	x++;
	int r=0;
	while(x>0)
	{
		r+=c[x];
		x-=lowbit(x);
	}
	return r;
}
void up(int x)
{
	x++;
	while(x<N)
	{
		c[x]++;
		x+=lowbit(x);
	}
}
bool fr=true;
bool check(ll x)
{
	int i;
	ll cnt=0;
	memset(c,0,sizeof(c));
	up(f[0]);
	for(i=1;i<=n;i++)
	{
		int p=upper_bound(v,v+1+n,sum[i]-x)-v-1;
		//if(fr)printf("i:%d p:%d sum:%lld sum[i]-x:%lld\n",i,p,sum[i],sum[i]-x);
		cnt+=getsum(p);
		up(f[i]);
	}
	fr=false;
	//printf("x:%lld cnt:%lld \n",x,cnt);
	return cnt>=k;
}
int main()
{
	int i;
	scanf("%d%lld",&n,&k);
	for(i=1;i<=n;i++)
	{
		scanf("%d",a+i);
		sum[i]=sum[i-1]+a[i];
		b[i]=i;
	}
	sort(b,b+n+1,cmp);
	for(i=0;i<=n;i++)
	{
		v[i]=sum[b[i]];
		f[b[i]]=i;
	}
	///for(i=1;i<=n;i++)printf("%lld ",v[i]);puts("");
	ll low=(ll)n*(-INF),high=(ll)n*INF,mid;
	while(low<high-1)
	{
		mid=(low+high)/2;
		if(check(mid))low=mid;
		else high=mid;
	}
	printf("%lld\n",low);
	return 0;
}