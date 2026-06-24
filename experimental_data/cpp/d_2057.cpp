#include<bits/stdc++.h>
using namespace std;
constexpr int MN=200005;
int n,q;
long long a[MN];
struct segt
{
	int l,r;
	long long mx1,mn1,mx2,mn2,ans;
}T[MN*4];
inline void up(int i)
{
	T[i].mx1=max(T[i<<1].mx1,T[i<<1|1].mx1);
	T[i].mx2=max(T[i<<1].mx2,T[i<<1|1].mx2);
	T[i].mn1=min(T[i<<1].mn1,T[i<<1|1].mn1);
	T[i].mn2=min(T[i<<1].mn2,T[i<<1|1].mn2);
	T[i].ans=max(max(T[i<<1].ans,T[i<<1|1].ans),max(T[i<<1].mx1-T[i<<1|1].mn1,T[i<<1].mx2-T[i<<1|1].mn2));
}
inline void con(int i,int x)
{
	T[i].mx1=T[i].mn1=a[x]+x;
	T[i].mx2=T[i].mn2=x-a[x];
	T[i].ans=0;
}
void build(int i,int l,int r)
{
	T[i].l=l,T[i].r=r;
	if(l==r)
	{
		con(i,l);
		return;
	}
	int mid=(l+r)>>1;
	build(i<<1,l,mid);
	build(i<<1|1,mid+1,r);
	up(i);
}
void change(int i,int x,int y)
{
	if(T[i].l==T[i].r)
	{
		a[x]=y;
		con(i,x);
		return;
	}
	if(x>T[i<<1].r)
		change(i<<1|1,x,y);
	else
		change(i<<1,x,y);
	up(i);
}
inline void getans()
{
	printf("%lld\n",T[1].ans);
}
inline void work()
{
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
		scanf("%lld",a+i);
	build(1,1,n);
	getans();
	while(q--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		change(1,x,y);
		getans();
	}
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
		work();
	return 0;
}