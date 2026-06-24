//#include<bits/stdc++.h>
#include<iostream>
#include<queue>
#include<iomanip>
#include<cctype>
#include<cstdio>
#include<deque>
#include<utility>
#include<cmath>
#include<ctime>
#include<cstring>
#include<string>
#include<cstdlib>
#include<vector>
#include<algorithm>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#define INF 1000000000
#define inf 1000000000
#define ll long long
#define db double
#define pb push_back
#define un unsigned
#define mod 1000000007
#define ll long long 
using namespace std;
inline ll read()
{
	ll x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
const int MAXN=200010;
ll T,n,s,sum,minn,maxx,bc,top,cnt0,cnt1;
struct wy
{
	ll x,y;
}t[MAXN],w[MAXN],p[MAXN];
ll b[MAXN];
inline ll cmp(wy a,wy b)
{
	return a.y<b.y;
}
inline ll cmp1(wy a,wy b)
{
	return a.x>b.x;
}
inline ll cmp2(wy a,wy b)
{
	return a.x<b.x;
}
inline ll check(ll x)
{
	top=cnt0=cnt1=0;
	sum=s;
	for(int i=1;i<=n;++i)
		if(t[i].y<x)
		{
			sum-=t[i].x;
			++cnt0;
		}
		else break;
	for(int i=1;i<=n;++i)
		if(w[i].x>x)
		{
			sum-=w[i].x;
			++cnt1;
		}
		else break;
	if(cnt0>=bc)return 0;
	if(cnt1>=bc)return 0;
	if(sum<0)return 0;
	for(int i=1;i<=n;++i)
	{
		if(p[i].x<=x&&p[i].y>=x)
			b[++top]=p[i].x;
	}
	if(cnt0>=cnt1)//小的较多
	{
		cnt0-=cnt1;
		while(cnt0)
		{
			sum-=x;
			--top;
			--cnt0;
		}
		--top;sum-=x;
		ll l=1;
		while(l<=top)
		{
			sum-=b[l];
			++l;--top;
			sum-=x;
		}
		if(sum<0)return 0;
		return 1;
	}
	else//多的较多
	{
		cnt1-=cnt0;
		for(int i=1;i<top;++i)
		{
			if(cnt1)
			{
				sum-=b[i];
				--cnt1;
			}
			else
			{
				sum-=b[i];
				--top;
				sum-=x;
			}
		}
		sum-=x;
		if(sum<0)return 0;
		return 1;
	}
	return 0;
}
signed main()
{
	//freopen("1.in","r",stdin);
	T=read();
	while(T--)
	{
		n=read();s=read();
		maxx=minn=0;
		bc=(n>>1)+1;
		for(int i=1;i<=n;++i)
		{
			ll x,y;
			x=read();y=read();
			t[i]=(wy){x,y};
			w[i]=(wy){x,y};
			p[i]=(wy){x,y};
			maxx=max(maxx,y);
			b[i]=x;
		}
		sort(b+1,b+1+n);
		sort(t+1,t+1+n,cmp);
		sort(w+1,w+1+n,cmp1);
		sort(p+1,p+1+n,cmp2);
		minn=b[bc];
		ll l=minn,r=maxx;
		while(l+1<r)
		{
			ll mid=(l+r)>>1;
			if(check(mid))l=mid;
			else r=mid;
		}
		if(check(r))printf("%lld\n",r);
		else printf("%lld\n",l);
	}
	return 0;
}