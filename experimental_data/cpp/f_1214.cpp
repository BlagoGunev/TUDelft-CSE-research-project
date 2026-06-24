#include <bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
struct Val{
	int val,kind,num;
}v[800010];
int f[800010];
bool cmp(Val a,Val b)
{
	return a.val<b.val;
}
long long c1[800010],c2[800010];
const int N=400000;
int A[800010],B[800010],a[800010];
int main()
{
	int m,n;
	scanf("%d %d",&m,&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&v[i].val);
		v[i].kind=1;
		v[i].num=i;
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&v[i+n].val);
		v[i+n].kind=-1;
		v[i+n].num=i;
	}
	sort(v+1,v+2*n+1,cmp);
	long long fans=1e18;
	long long ans=0;
	for(int i=1;i<=2*n;i++)
	{
		f[i]=f[i-1]+v[i].kind;
		if(v[i].kind>0)
		{
			if(f[i]>0)ans-=v[i].val;
			else ans+=v[i].val;
			c1[f[i]+N]+=v[i].val;
		}
		else{
			if(f[i]<0)ans-=v[i].val;
			else ans+=v[i].val;
			c2[f[i]+N]+=v[i].val;
		}
	}
	int pos=0;
	for(int i=1;i<=2*n;i++)
	{
		if(ans<fans){
			fans=ans;
			pos=i;
		}
		v[i+2*n]=v[i];
		v[i+2*n].val+=m;
		int cur=f[i-1]+N;
		if(v[i].kind>0)
		{
			ans+=2*c1[cur+1];
			ans-=2*c2[cur];
			ans+=m;
			c1[f[i]+N]+=m;
		}
		else{
			ans-=2*c1[cur];
			ans+=2*c2[cur-1];
			ans+=m;
			c2[f[i]+N]+=m;
		}
	}
	printf("%lld\n",fans);
	int now1=0,now2=0;
	for(int i=pos;i<pos+2*n;i++)
	{
		if(v[i].kind>0)
		{
			A[++now1]=v[i].num;
		}
		else B[++now2]=v[i].num;
	}
	for(int i=1;i<=n;i++)
		a[A[i]]=B[i];
	for(int i=1;i<=n;i++)
		printf("%d ",a[i]);
	return 0;
}