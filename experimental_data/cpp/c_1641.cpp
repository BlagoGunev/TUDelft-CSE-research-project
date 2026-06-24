#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;
#define ll long long
const int N=2e5+5,I=1e9;
int read()
{
	int x=0,y=1;
	char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') y=0;
	for(;isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+(c^48);
	return y?x:-x;
}
#define tomin(x,y) x=min(x,y)
int n,m;
struct _T
{
	int l,r;
	int mn;
}tr[N<<2];
#define ls (o<<1)
#define rs (o<<1|1)
void build(int o,int l,int r)
{
	tr[o]=(_T){l,r,I};
	if(l==r) return;
	build(ls,l,(l+r>>1));
	build(rs,(l+r>>1)+1,r);
}
void up_(int o) { tr[o].mn=min(tr[ls].mn,tr[rs].mn); }
void change(int o,int x,int y)
{
	if(tr[o].l==tr[o].r) { tomin(tr[o].mn,y); return; }
	if(tr[ls].r>=x) change(ls,x,y);
	else change(rs,x,y);
	up_(o);
}
int query(int o,int l,int r)
{
	if(tr[o].l>=l&&tr[o].r<=r) return tr[o].mn;
	if(tr[ls].r>=r) return query(ls,l,r);
	if(tr[rs].l<=l) return query(rs,l,r);
	return min(query(ls,l,r),query(rs,l,r));
}
set<int> se;
#define IT set<int>::iterator 
void upd(int l,int r)
{
	IT it=se.lower_bound(l);
	for(IT it2;(*it)<=r;it=it2)
	{
		it2=it,it2++;
		se.erase(it);
	}
}
IT las(IT x) { return --x; }
int gets(int x)
{
	if(!se.count(x)) return 1;
	int ql=*las(se.lower_bound(x))+1,qr=*se.upper_bound(x)-1;
	return query(1,ql,x)<=qr?0:2;
}
signed main()
{
	n=read(),m=read();
	build(1,1,n);
	for(int i=0;i<=n+1;i++) se.insert(i);
	while(m--)
	{
		int op=read();
		if(op==0)
		{
			int l=read(),r=read(),x=read();
			if(x==0) upd(l,r);
			else change(1,l,r);
		}
		else
		{
			int x=read(),y=gets(x);
			if(y==0) puts("YES");
			if(y==1) puts("NO");
			if(y==2) puts("N/A");
		}
	}
	return 0;
}
/*
1
3
45 45 50
20 45 10
52 52 50
*/