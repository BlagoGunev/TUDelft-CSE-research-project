#include<bits/stdc++.h>
#define cint const int
#define iint inline int
#define uint unsigned int
#define iuint inline unsigned int
#define cuint const unsigned int
#define ll long long
#define cll const long long
#define ill inline long long
#define ull unsigned long long
#define iull inline unsigned long long
#define cull const unsigned long long
#define sh short
#define csh const short
#define ish inline short
#define ush unsigned short
#define iush inline unsigned short
#define cush const unsigned short
using namespace std;
iint read()
{
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<1)+(x<<3)+(ch-'0');
		ch=getchar();
	}
	return x;
}
cint inf=1e9;
int n;
int a[500001],b[500001];
namespace T{
	struct node{
		int l,r,mn;
	}t[2000001];
	void Build(cint p,cint l,cint r)
	{
		t[p].l=l;
		t[p].r=r;
		if(l==r)
		{
			t[p].mn=a[l];
			return;
		}
		cint mid=l+r>>1;
		Build(p<<1,l,mid);
		Build(p<<1|1,mid+1,r);
		t[p].mn=min(t[p<<1].mn,t[p<<1|1].mn);
	}
	void build()
	{
		Build(1,1,n);
	}
	int Ask(cint p,cint l,cint r)
	{
		if(t[p].l>r||t[p].r<l)return inf;
		if(t[p].l>=l&&t[p].r<=r)return t[p].mn;
		return min(Ask(p<<1,l,r),Ask(p<<1|1,l,r));
	}
	int ask(cint l,cint r)
	{
		return Ask(1,l,r);
	}
	int Find(cint p,cint l,cint r,cint x)
	{
		if(t[p].l>r||t[p].r<l)return -1;
		if(t[p].l>=l&&t[p].r<=r&&t[p].mn!=x)return -1;
		if(t[p].l==t[p].r)return t[p].l;
		int L=Find(p<<1,l,r,x);
		if(L!=-1)return L;
		return Find(p<<1|1,l,r,x);
	}
	int find(cint l,cint r,cint x)
	{
		return Find(1,l,r,x);
	}
}
int find(cint l,cint r,cint x)
{
	cint mid=l+r+1>>1;
	if(l>=r)return mid;
	if(b[mid]<x)return find(mid,r,x);
	return find(l,mid-1,x);
}
int solve(cint l,cint r)
{
	if(l>r)return 0;
	int mn=T::ask(l,r);
	vector<int>p;
	int w=l;
	p.push_back(l-1);
	while(1)
	{
		w=T::find(w,r,mn);
		if(w==-1)break;
		p.push_back(w);
		++w;
	}
	int lst=find(0,n,mn);
	p.push_back(r+1);
	int ans=inf;
	for(int i=0;i<p.size()-1;++i)
	{
		cint pl=p[i]+1,pr=p[i+1]-1;
		cint len=pr-pl+1,tp=n-len;
		if(b[tp]>mn)continue;
		if(tp<=lst)
		{
			ans=min(ans,solve(pl,pr));
		}
		else
		{
			ans=min(ans,solve(pl,pr)+tp-lst);
		}
	}
	return ans;
}
int main()
{
	n=read();
	for(int i=1;i<=n;++i)
	{
		a[i]=read();
	}
	for(int i=1;i<=n;++i)
	{
		b[i]=read();
	}
	T::build();
	sort(b+1,b+n+1);
	int ans=solve(1,n);
	printf("%d",(ans==inf?-1:ans));
	return 0;
}